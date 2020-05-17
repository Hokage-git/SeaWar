#pragma once

void draw(int n);
void interfaceA(int(&a)[12][12]);
void interfaceB(int(&a)[12][12]);
void wall(int(&map)[12][12], int(&emap)[12][12]);
void f_deck(int(&map)[12][12]);
void tree_deck(int(&map)[12][12]);
void two_deck(int(&map)[12][12]);
void one_deck(int(&map)[12][12]);
void ef_deck(int(&emap)[12][12]);
void etree_deck(int(&emap)[12][12]);
void etwo_deck(int(&emap)[12][12]);
void eone_deck(int(&emap)[12][12]);
void flex(int(&emap)[12][12], int(&map)[12][12]);
void shoot(int(&emap)[12][12], int(&map)[12][12]);