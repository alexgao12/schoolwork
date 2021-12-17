#include "Playlist.h"

void PrintMenu(string title);
void readInput(string input);
void outputPlaylist(PlaylistNode* head);
void addSong();
void removeSong();
void changePosition();
void outputArtist();
void totalTime();

PlaylistNode* head = nullptr;
PlaylistNode* tail = nullptr;
int length = 0;

int main (){
    
    string title;
    string input;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;

    while (true){
        PrintMenu(title);
        cin >> input;
        cout << endl;
        readInput(input);
    }

    return 0;
}

void PrintMenu(string title){
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
}

void readInput(string input){
    if(input == "a"){ //add
        addSong();
    }
    if(input == "d"){ //remove
        removeSong();
    }
    if(input == "c"){ //change
        changePosition();
    }
    if(input == "s"){ //output by artist
        outputArtist();
    }
    if(input == "t"){ //total time
        totalTime();
    }
    if(input == "o"){ //output playlist
        outputPlaylist(head);
    }
    if(input == "q"){ //quit
        exit(0);
    }
}

void outputPlaylist(PlaylistNode* head){
    if (head != nullptr){
        unsigned i = 1;
        for(PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
            cout << i << "." << endl;
            currNode->PrintPlaylistNode();
            cout << endl;
            ++i;
        }
    }
    else{
        cout << "Playlist is empty" << endl;
        cout << endl;
    }
}

void addSong(){
    string id;
    string songName;
    string artistName;
    int songLength; 
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID: " << endl;
    cin >> id;
    cout << endl;
    cout << "Enter song's name: " << endl;
    cin.ignore();
    getline(cin, songName);
    cout << endl;
    cout << "Enter artist's name: " << endl;
    getline(cin, artistName);
    cout << endl;
    cout << "Enter song's length (in seconds): " << endl;
    cin >> songLength;
    cout << endl;

    PlaylistNode* temp = new PlaylistNode(id, songName, artistName, songLength);
    if(head != nullptr){
        tail->SetNext(temp);
        tail = tail->GetNext();
    }
    else{
        head = temp;
        tail = temp;
    }

    ++length;
}

void removeSong(){
    string id;
    PlaylistNode* temp;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> id;
    cout << endl;
    if(head == nullptr){
        cout << "Playlist is already empty" << endl;
    }
    if(head->GetID() == id){
        temp = head;
        cout << "\"" << temp->GetSongName() << "\" removed" << endl;
        head = head->GetNext();
        delete temp;
        temp = nullptr;
        if(head == nullptr){
            tail = nullptr;
        }
        --length;
    }
    else{
        for(PlaylistNode* currNode = head;currNode->GetNext() != nullptr;currNode = currNode->GetNext()){
            if(currNode->GetNext()->GetID() == id){
                temp = currNode->GetNext();
                cout << "\"" << temp->GetSongName() << "\" removed" << endl << endl;
                currNode->SetNext(currNode->GetNext()->GetNext());
                delete temp;
                temp = nullptr;
                if(currNode->GetNext() == nullptr){
                    tail = currNode;
                }
                --length;
                return; 
            }
        }
        cout << "Song not found" << endl;
    }
}

void changePosition(){
    cout << length << endl;
    int currPos;
    int newPos;
    PlaylistNode* currNode = head;
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> currPos;
    cout << endl;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;
    cout << endl;
    if(currPos > 1){
        for(int i = 1; i < currPos - 1; ++i){
            currNode = currNode->GetNext();
        }
        PlaylistNode* temp = currNode;
        currNode = currNode->GetNext();
        temp->SetNext(currNode->GetNext());
    }
    if(currNode == head){
        head = head->GetNext();
    }
    if(newPos <= 1){
        currNode->SetNext(head->GetNext());
        head = currNode;
    }
    if(newPos >= length){
        tail->InsertAfter(currNode);
        tail = tail->GetNext();
        cout << "\"" << currNode->GetSongName() << "\" moved to position " << newPos << endl;
    }
    else{
        // if(currNode == head){
        //     head = head->GetNext();
        // }
        if(currNode == tail){
            for(PlaylistNode* temp = head; temp != nullptr; temp = temp->GetNext()){
                if(temp->GetNext() == tail){
                    tail = temp;
                    tail->SetNext(nullptr);
                }
            }
        }
        PlaylistNode* newNode = head;
        // for(int i = 1; i < newPos; ++i){
        //     if(i == newPos - 1){
        //         newNode->InsertAfter(currNode);
        //         cout << "\"" << currNode->GetSongName() << "\" moved to position " << newPos << endl;
        //     }
        //     newNode = newNode->GetNext();
        // }
        for(int i = 0; i < newPos; ++i){
            if(i == newPos - 2){
                newNode->InsertAfter(currNode);
                cout << "\"" << currNode->GetSongName() << "\" moved to position " << newPos << endl;
            }
            newNode = newNode->GetNext();
        }
    }

}

void outputArtist(){
    string artistName;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    getline(cin, artistName);
    getline(cin, artistName);
    cout << endl;

    if (head != nullptr){
        unsigned i = 1;
        for(PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
            if(currNode->GetArtistName() == artistName){
                cout << i << "." << endl;
                currNode->PrintPlaylistNode();
                cout << endl;
                ++i;
            }
        }
    }
    else{
        cout << "Playlist is empty" << endl;
        cout << endl;
    }
}

void totalTime(){
    cout << "OUTPUT TOTAL TIME OF PLAYLIST IN SECONDS" << endl;
    cout << "Total Time: ";
    int time = 0;
    for(PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
            time += currNode->GetSongLength();
    }
    cout << time << " seconds" << endl;
    cout << endl;
}