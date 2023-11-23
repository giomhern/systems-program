#ifndef MUSIC_H
#define MUSIC_H

typedef struct {
    char title[100];
    char artist[100];
    int duration; // in seconds
} song;

typedef struct album {
    char name[100];
    song *songs;
    struct album *next;
} album;

// Practice Problems:

// 1. Implement a function to add a new `song` to an `album`.
// 2. Write a function to remove a song from an album by title.
// 3. Create a function to print all songs in an album.
// 4. Implement a linked list of albums and add a function to insert a new album.
// 5. Write a function to find a song across all albums.

void addSongToAlbum(album *a, song *s);
void removeSongFromAlbum(album *a, char *title);
void printSongsInAlbum(const album *a);
void insertAlbum(album **head, album *newAlbum);
song *findSongInAlbums(const album *head, char *title);

#endif // MUSIC_H
