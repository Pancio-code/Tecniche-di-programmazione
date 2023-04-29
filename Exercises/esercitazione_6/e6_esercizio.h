#pragma once

int lunghezza(char *s);
int char_in_posizione(char* s, char ch);
int char_in_posizione_aux(char* s, char ch, int i);
void vec_integral(float* v, int n);
void vec_integral_aux(float* v, int n, int i, float sum_till_now);
float vec_dot(float* v1, float* v2, int n);

