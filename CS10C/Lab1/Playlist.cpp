#include "Playlist.h"

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) { }
PlaylistNode::PlaylistNode(string id, string songName, string artistName, int songLength) : uniqueID(id), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr){ }

void PlaylistNode::InsertAfter(PlaylistNode* target){
    if(target != this->GetNext()){
        target->SetNext(this->GetNext());
        this->SetNext(target);
    }
}

void PlaylistNode::SetNext(PlaylistNode* next){
    this->nextNodePtr = next;
}

void PlaylistNode::PrintPlaylistNode() const{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds) : " << songLength << endl;
}
