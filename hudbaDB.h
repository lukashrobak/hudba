#pragma once

#define INTERPRET_SIZE 21
#define ALBUM_SIZE 21

struct t_album
{
    char  interpret[INTERPRET_SIZE];
    char album[ALBUM_SIZE];
    int   rok;
    struct t_album* dalsi;
};

void add(char* interpret,char* album, int rok, struct t_album** uk_prvni);
void del(int rok, struct t_album** uk_prvni);
