#include <iostream>

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

using namespace std;

class PlaylistNode{
    private: 
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;

    public:
        PlaylistNode();
        PlaylistNode(string id, string songName, string artistName, int songLength);   
        void InsertAfter(PlaylistNode* target);
        void SetNext(PlaylistNode* next);
        string GetID() const { return uniqueID; }
        string GetSongName() const { return songName; }
        string GetArtistName() const { return artistName; }
        int GetSongLength() const { return songLength; }
        PlaylistNode* GetNext()const { return nextNodePtr; }
        void PrintPlaylistNode() const;
};
        

#endif