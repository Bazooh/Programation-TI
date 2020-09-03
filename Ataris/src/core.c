
#include "core.h"

double rad(int16_t angle) {
    return (double)(angle * M_PI / 180);
}

int16_t deg(double angle) {
    return (int16_t)(angle * 180 / M_PI);
}

double primaryMeasure(double angle) {
    int16_t angle_deg;

    angle_deg = deg(angle);
    angle_deg %= 360;
    if (angle_deg < 0) { angle_deg += 360; }

    return rad(angle_deg);
}

uint8_t calculateContact(t_precision_pos *contact_point, t_precision_pos point_a, double a, double b, double c, double d) {
    uint8_t p1_is_in;
    uint8_t p2_is_in;
    double variables[7];

    a_2 = a*a;
    c_2 = c*c;
    delta = 4*(2*a*b*c*d - a_2*d*d - c_2*b*b + BALL_RAYON*BALL_RAYON*(a_2 + c_2));

    if (delta < 0) { return FALSE; }

    sqrt_delta = sqrt(delta);
    t1 = (-2*(a*b + c*d) - sqrt_delta) / (2*(a_2 + c_2));
    t2 = (-2*(a*b + c*d) + sqrt_delta) / (2*(a_2 + c_2));

    p1_is_in = FALSE;
    p2_is_in = FALSE;
    if (t1 >= 0 && t1 <= 1) {
        p1_is_in = TRUE;
    }
    if (t2 >= 0 && t2 <= 1) {
        p2_is_in = TRUE;
    }

    if (!(p1_is_in || p2_is_in)) { return FALSE; }

    if (p1_is_in && p2_is_in) {
        moy_t = (t1 + t2) / 2;
        contact_point->x = a*moy_t + point_a.x;
        contact_point->y = c*moy_t + point_a.y;
    } else if (p1_is_in) {
        contact_point->x = a*t1 + point_a.x;
        contact_point->y = c*t1 + point_a.y;
    } else {
        contact_point->x = a*t2 + point_a.x;
        contact_point->y = c*t2 + point_a.y;
    }
    return TRUE;
}

void setContactPoint(t_precision_pos *contact_points, t_precision_pos *contact_point, uint8_t *contact) {
    uint8_t i;
    uint8_t nb_contact;

    nb_contact = 0;

    while (contact[nb_contact]) { nb_contact++; }

    contact_point->x = 0;
    contact_point->y = 0;
    for (i = 0; i < nb_contact; ++i) {
        contact_point->x += contact_points[contact[i] - 1].x;
        contact_point->y += contact_points[contact[i] - 1].y;
    }
    contact_point->x /= nb_contact;
    contact_point->y /= nb_contact;
}

void resetContact(uint8_t *contact) {
    uint8_t i;
    for (i = 0; i < NUMBER_POINT_OBSTACLE; ++i) {
        contact[i] = 0;
    }
}

uint8_t ballDirection(t_ball ball) {
    uint8_t i;

    for (i = 0; i < NUMBER_DIRECTION - 1; ++i) {
        if (ball.direction >= DIRECTION[i][0] && ball.direction < DIRECTION[i][1]) { return i; }
    }
    return NUMBER_DIRECTION - 1;
}

uint8_t hurtObstacle(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, t_obstacle *obstacle) {
    if (obstacle->id) {
        --obstacle->life;
        if (!obstacle->life) {
            if (obstacle->in_matrix) {
                setAdjHiddenObstacle(matrix, obstacles, obstacle->matrix.x, obstacle->matrix.y, FALSE);
                matrix[obstacle->matrix.x][obstacle->matrix.y] = 0;
            }
            eraseObstacle(obstacle);
            removeObstacle(obstacles, obstacle->id);
            return TRUE;
        }
    }
    return FALSE;
}

uint8_t checkDirection(t_ball ball, uint8_t direction, t_precision_pos a, t_precision_pos b) {
    switch (direction) {
        case 0:
            if ((ball.pos.x > a.x && ball.pos.x > b.x) || (ball.pos.y < a.y && ball.pos.y < b.y)) { return FALSE; }
            break;
        case 1:
            if ((ball.pos.x < a.x && ball.pos.x < b.x) || (ball.pos.y < a.y && ball.pos.y < b.y)) { return FALSE; }
            break;
        case 2:
            if ((ball.pos.x < a.x && ball.pos.x < b.x) || (ball.pos.y > a.y && ball.pos.y > b.y)) { return FALSE; }
            break;
        case 3:
            if ((ball.pos.x > a.x && ball.pos.x > b.x) || (ball.pos.y > a.y && ball.pos.y > b.y)) { return FALSE; }
            break;
    }
    return TRUE;
}

uint8_t preCheck(t_ball ball, uint8_t direction, t_precision_pos a, t_precision_pos b, uint8_t hide) {
    if (hide) { return FALSE; }
    if (!checkDirection(ball, direction, a, b)) { return FALSE; }
    return TRUE;
}

uint8_t calculateContactOrtho(t_ball ball, t_precision_pos *contact_point, uint8_t ortho, t_precision_pos a, t_precision_pos b) {
    double ac_x, ac_y, t;

    ac_x = ball.pos.x - a.x;
    ac_y = ball.pos.y - a.y;

    if (ortho == HORIZONTAL && abs(ac_y) <= BALL_RAYON) {
        t =  ac_x / (b.x - a.x);

        if (t >= 0 && t <= 1) {
            contact_point->x = ball.pos.x;
            contact_point->y = a.y;
            return TRUE;
        }
    } else if (ortho == VERTICAL && abs(ac_x) <= BALL_RAYON) {
        t = ac_y / (b.y - a.y);

        if (t >= 0 && t <= 1) {
            contact_point->x = a.x;
            contact_point->y = ball.pos.y;
            return TRUE;
        }
    }
    return FALSE;
}

uint8_t checkOrthoDistance(t_ball ball, t_precision_pos a, t_precision_pos b, uint8_t ortho) {
    double ac, bc;

    switch (ortho) {
        case FALSE:
            return FALSE;
        case HORIZONTAL:
            ac = abs(ball.pos.x - a.x);
            bc = abs(ball.pos.x - b.x);
            break;
        case VERTICAL:
            ac = abs(ball.pos.y - a.y);
            bc = abs(ball.pos.y - b.y);
            break;
    }
    if (ac > BALL_RAYON && bc > BALL_RAYON) { return TRUE; }
    return FALSE;
}

void addContact(uint8_t *contact, uint8_t n) {
    uint8_t i;

    i = 0;

    while (contact[i]) { ++i; }
    contact[i] = n;
}

void setAB(t_obstacle *obstacle, t_precision_pos *a, t_precision_pos *b, uint8_t *j_a, uint8_t *j_b, uint8_t j, uint8_t direction) {
    *j_a = direction + j;
    *j_a %= NUMBER_POINT_OBSTACLE;
    *j_b = (*j_a) + 1;
    *j_b %= NUMBER_POINT_OBSTACLE;

    a->x = (double)obstacle->point[*j_a].x;
    a->y = (double)obstacle->point[*j_a].y;
    b->x = (double)obstacle->point[*j_b].x;
    b->y = (double)obstacle->point[*j_b].y;
}

uint8_t getContactPoint(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, t_ball ball, t_precision_pos *contact_point) {
    uint8_t i, j, j_a, j_b, nb_obstacle, ball_direction;
    t_precision_pos a, b;
    uint8_t contact[NUMBER_POINT_OBSTACLE];
    t_precision_pos contact_points[NUMBER_POINT_OBSTACLE];
    t_obstacle *obstacle;

    obstacle = obstacles;

    nb_obstacle = nbObstacle(obstacles);
    ball_direction = ballDirection(ball);
    resetContact(contact);

    for (i = 0; i < nb_obstacle; ++i) {
        for (j = 0; j < NUMBER_SIDE_TO_CHECK; ++j) {
            setAB(obstacle, &a, &b, &j_a, &j_b, j, ball_direction);

            if (!preCheck(ball, ball_direction, a, b, obstacle->hide[j_a])) { continue; }

            if (checkOrthoDistance(ball, a, b, obstacle->ortho[j_a])) {
                if (calculateContactOrtho(ball, &contact_points[j_a], obstacle->ortho[j_a], a, b)) {
                    addContact(contact, j_a + 1);
                }
                continue;
            }

            if (calculateContact(&contact_points[j_a], a, b.x - a.x, a.x - ball.pos.x, b.y - a.y, a.y - ball.pos.y)) {
                addContact(contact, j_a + 1);
            }
        }
        if (contact[0]) {
            for (j = NUMBER_SIDE_TO_CHECK; j < NUMBER_POINT_OBSTACLE; ++j) {
                setAB(obstacle, &a, &b, &j_a, &j_b, j, ball_direction);

                if (calculateContact(&contact_points[j_a], a, b.x - a.x, a.x - ball.pos.x, b.y - a.y, a.y - ball.pos.y)) {
                    addContact(contact, j_a + 1);
                }
            }
            setContactPoint(contact_points, contact_point, contact);
            if (!hurtObstacle(matrix, obstacles, obstacle) && obstacle->life) { printObstacle(obstacle); }
            return TRUE;
        }
        obstacle = obstacle->next;
    }
    return FALSE;
}

void turnBall(t_ball *ball, t_precision_pos contact_point) {
    if (ball->pos.x == contact_point.x) {
        ball->direction = primaryMeasure(-(ball->direction));
    } else {
        ball->direction = primaryMeasure(2*(atan((contact_point.y - ball->pos.y) / (ball->pos.x - contact_point.x))) + M_PI - ball->direction);
    }
    dbg_sprintf(dbgout, " ball direction : %d\n", deg(ball->direction));
}

void initSpeed(double *speed, double *speed_total, uint32_t *nb_speed) {
    *speed = SPEED*timer_1_Counter;
    (*nb_speed)++;
    *speed_total += *speed;
    dbg_sprintf(dbgout, "          speed : %d.%d\n", (int)*speed, (int)(*speed*1000000 - (int)*speed*1000000));
    //dbg_sprintf(dbgout, "timer_1_Counter : %d\n", timer_1_Counter);
    timer_1_Counter = 0;
}

void ballMove(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, t_ball *ball, double *speed_total, uint32_t *nb_speed) {
    double speed;
    t_ball checking_ball;
    t_precision_pos contact_point;

    checking_ball = *ball;
    initSpeed(&speed, speed_total, nb_speed);

    checking_ball.pos.x += cos(checking_ball.direction)*speed;
    checking_ball.pos.y -= sin(checking_ball.direction)*speed;

    if (getContactPoint(matrix, obstacles, checking_ball, &contact_point)) {
        turnBall(&checking_ball, contact_point);
    }
    checking_ball.old_pos.x = (uint24_t)ball->pos.x;
    checking_ball.old_pos.y = (uint8_t)ball->pos.y;
    *ball = checking_ball;
}