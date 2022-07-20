#include <iostream>
#include <string>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl
      << "a - Add song" << endl
      << "d - Remove song" << endl
      << "c - Change position of song" << endl
      << "s - Output songs by specific artist" << endl
      << "t - Output total time of playlist (in seconds)" << endl
      << "o - Output full playlist" << endl
      << "q - Quit" << endl << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {   
   PlaylistNode* tempNode = 0;
   PlaylistNode* trashNode = 0;
   string songID, songName, artistName;
   int length, origin, destination;
   switch(option){
      case 'q': //quit
         break;
         
      case 'a': //addsong
         cout << "ADD SONG" << endl;
         cout << "Enter song's unique ID:" << endl;
         cin.ignore();
         getline(cin, songID);
         cout << "Enter song's name:" << endl;
         getline(cin, songName);
         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);
         cout << "Enter song's length (in seconds):" << endl;
         cin >> length;
         
         cout << endl;
         // checks if playlist empty, if yes add the first song as headnode
         if(headNode->GetID() == "none"){
            delete headNode;
            headNode = new PlaylistNode(songID, songName, artistName, length);
         }else{ // check if headnode is only song, else iterate through to last song in list
            PlaylistNode* addedNode = new PlaylistNode(songID, songName, artistName, length);
            if(headNode->GetNext() == 0){
               headNode->SetNext(addedNode);
            }else{
               tempNode = headNode;
               while(tempNode->GetNext() != 0){
                  tempNode = tempNode->GetNext();
               }
               tempNode->SetNext(addedNode);
            }
         }
         break;
        
      case 'd': //removesong
         cout << "REMOVE SONG" << endl
               << "Enter song's unique ID:" << endl;
         //prompt user
         cin.ignore();
         getline(cin, songID);
         // find node matching unique ID and remove first instance
         tempNode = headNode;
         while(tempNode->GetNext()->GetID() != songID)
            tempNode = tempNode->GetNext();
         trashNode = tempNode->GetNext();
         tempNode->SetNext(trashNode->GetNext());
         cout << "\"" << trashNode->GetSongName() << "\" removed." << endl << endl;
         delete trashNode;
         break;
        
      case 'c': //changeposition
         cout << "CHANGE POSITION OF SONG" << endl
            << "Enter song's current position:" << endl;
         cin >> origin;
         cout << "Enter new position for song:" << endl;
         cin >> destination;
         tempNode = headNode;
         
         //MOVE/INSERT LOGIC
         if(origin == 1 && origin != destination){
            // MOVE HEAD NODE UP
            //sets tempNode to destination node
            for(int i=1;tempNode->GetNext() != 0; i++){
               if(i == destination){
                  trashNode = headNode;
                  //sets new headnode
                  headNode = headNode->GetNext();
                  //inserts old headnode after destination node
                  tempNode->InsertAfter(trashNode);
               }
               tempNode = tempNode->GetNext();
            }
            cout << "\"" << trashNode->GetSongName() << "\" moved to position " << destination << endl;
            // done?
         }else if(origin < destination){ //MOVING ALL OTHER NODES UP
            for(int i=1; i < destination; i++){ // set node BEFORE origin
               if(i == origin-1){
                  trashNode = tempNode->GetNext(); //copy origin node
                  tempNode->SetNext(trashNode->GetNext()); //close the gap
               }
               if(i == destination - 1){
                  tempNode->InsertAfter(trashNode); //insert copied node after destination node
                  cout << "\"" << trashNode->GetSongName() << "\" moved to position " << destination << endl;
               }
               tempNode = tempNode->GetNext();
            }
         }else if(destination == 1){ // Moving a node to the head
            for(int i=1;tempNode->GetNext() != 0; i++){
               
               if(i == origin-1){
                  trashNode = tempNode->GetNext(); // copy origin
                  tempNode->SetNext(trashNode->GetNext()); // close the gap
               }
               tempNode = tempNode->GetNext();
            }
            tempNode = headNode; // copy the head
            headNode = trashNode; // replace with new head
            headNode->SetNext(tempNode); // point the new head to the old head 
            cout << "\"" << trashNode->GetSongName() << "\" moved to position " << destination << endl;
            break;
         }else if(origin > destination){ // MOVE NODE DOWN
            for(int i=1;tempNode->GetNext() != 0; i++){
               if(i == origin-1){
                  trashNode = tempNode->GetNext(); //copy origin
                  tempNode->SetNext(trashNode->GetNext()); // close the gap
                  break;
               }
               tempNode = tempNode->GetNext();

            }
            tempNode = headNode;
            for(int i=1;tempNode->GetNext() != 0;i++){
               if(i == destination-1){
                  tempNode->InsertAfter(trashNode);
                  cout << "\"" << trashNode->GetSongName() << "\" moved to position " << destination << endl;
               }
               tempNode = tempNode->GetNext();
            }
         }
         cout << endl;
         break;

      case 's': //song by artist
         cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl
            << "Enter artist's name:" << endl << endl;
         cin.ignore();
         getline(cin, artistName);
         tempNode = headNode;
         for(int i=1;tempNode!=nullptr;i++){
            if(tempNode->GetArtistName() == artistName){
               cout << i << "." << endl;
               tempNode->PrintPlaylistNode();
            }
            tempNode = tempNode->GetNext();
         }
         break;
         
      case 't': // total time in seconds
         length = 0;
         tempNode = headNode;
         for(int i=1;tempNode != nullptr;i++){
            length += tempNode->GetSongLength();
            tempNode = tempNode->GetNext();
         }
         // output
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl
            << "Total time: " << length << " seconds" << endl << endl;
         break;
         
      case 'o': // output full playlist
         cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
         if (headNode == nullptr){
            cout << "Playlist is empty" << endl << endl;
         }else if (headNode->GetID() == "none"){
            cout << "Playlist is empty" << endl << endl;
         }else{
            tempNode = headNode;
            for(int i=1;tempNode!=0;i++){
               cout << i << "." << endl;
               tempNode->PrintPlaylistNode();
               tempNode = tempNode->GetNext();
            }
         }
         break;
   }
   return headNode;
}

int main() {
   string playlistTitle;
   char optionIn;
   PlaylistNode* headNode = new PlaylistNode();
   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);
   
   while(optionIn !='q'){
      PrintMenu(playlistTitle);
      cout << "Choose an option:" << endl;
      cin >> optionIn;
      headNode = ExecuteMenu(optionIn, playlistTitle, headNode);
   }
   
   return 0;
}