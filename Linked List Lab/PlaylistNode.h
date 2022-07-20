#ifndef _PLAYLIST_NODE_H_
#define _PLAYLIST_NODE_H_
#include <string>
using namespace std;

class PlaylistNode{
    
    // functions
    public:
      PlaylistNode();
      PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
      void InsertAfter(PlaylistNode* previousNode); // - Mutator (1 pt)
      void SetNext(PlaylistNode* nextNode); // - Mutator (1 pt)
      string GetID() const; // - Accessor
      string GetSongName() const; // - Accessor
      string GetArtistName() const; // - Accessor
      int GetSongLength() const; // - Accessor
      PlaylistNode* GetNext() const; // - Accessor
      void PrintPlaylistNode() const; // Print Function
    private:
      string uniqueID; //Initialized to "none" in default constructor
      string songName; //Initialized to "none" in default constructor
      string artistName; //Initialized to "none" in default constructor
      int songLength; //Initialized to 0 in default constructor
      PlaylistNode* nextNodePtr; //Initialized to 0 in default constructor
};
#endif