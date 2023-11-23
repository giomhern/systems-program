#include <stdio.h>
#include <stdlib.h>
#include "music.h"
#include <string.h>

void addSongToAlbum(album *a, song *s, int song_length){
    if(!a || !s) return;
    int new_alb_length = song_length + 1;
    a->songs = realloc(a->songs, (song_length + 1) * sizeof(song));
    if(!a->songs) return;
    a->songs[new_alb_length] = *s;
}

void remove_song_from_album(album* a, char* title){
    for(unsigned int i = 0; i < 5; i++){
        if(strcmp(a->songs[i].title, title) == 0){
            for(unsigned int j = i; j < 4; j++){
                a->songs[j] = a->songs[j + 1];
            }
            a->songs = realloc(a->songs, 4 * sizeof(song));
            return;
        }
    }

}