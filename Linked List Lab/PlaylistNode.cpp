// playlistNode.cpp
#include "PlaylistNode.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
   
   PlaylistNode::PlaylistNode(){
      uniqueID = "none"; //Initialized to "none" in default constructor
      songName = "none"; //Initialized to "none" in default constructor
      artistName = "none"; //Initialized to "none" in default constructor
      songLength = 0; //Initialized to 0 in default constructor
      nextNodePtr = 0; //Initialized to 0 in default constructor
   }
    
   PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength){
      this->uniqueID = uniqueID;
      this->songName = songName;
      this->artistName = artistName;
      this->songLength = songLength;
   }
   void PlaylistNode::InsertAfter(PlaylistNode* targetNode){
      PlaylistNode* tempPtr = nullptr;
      tempPtr = this->nextNodePtr;
      this->nextNodePtr = targetNode;
      targetNode->nextNodePtr = tempPtr;
   }
   void PlaylistNode::SetNext(PlaylistNode* nextNode){
      nextNodePtr = nextNode;
   }
   string PlaylistNode::GetID() const{
      return uniqueID; //Initialized to "none" in default constructor
   }
   string PlaylistNode::GetSongName() const{
      return songName; //Initialized to "none" in default constructor
   }
   string PlaylistNode::GetArtistName() const{
      return artistName; //Initialized to "none" in default constructor
   }
   int PlaylistNode::GetSongLength() const{
      return songLength; //Initialized to 0 in default constructor
   }
   PlaylistNode* PlaylistNode::GetNext() const{
      return nextNodePtr; 
   }
   void PlaylistNode::PrintPlaylistNode() const{
      cout << "Unique ID: " << uniqueID << endl
         << "Song Name: " << songName << endl
         << "Artist Name: " << artistName << endl
         << "Song Length (in seconds): " << songLength << endl << endl;
   }