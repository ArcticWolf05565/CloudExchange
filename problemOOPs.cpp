#include <iostream>
#include <string>
#include <vector>

class Playlist{
    private:
    std::string playlist;
    std::vector<std::string> songName;

    public:
    Playlist(std::string playlist) : playlist(playlist){}

    void addSong(std::string songname){
        songName.push_back(songname);
    }
    void removeSong(std::string songname){
        for(auto name: songName){
            if(name == songname ){
                name.erase();
                break;
            }
        }
    }
    std::string getPlaylistName(){
        return playlist;
    }
    std::string getAllSongs(){
        std::string allSongs = songName.front();
        for(auto songs : songName){
            allSongs += "," + songs;
        }
        return allSongs;
    }
    
};

int main(){

    Playlist music("My Playlist");

    music.addSong("Faded");
    music.addSong("You belong with me");
    music.addSong("sapphire");

    music.removeSong("Faded");

    std::cout << music.getAllSongs() << std::endl;
    return 0;
}