#ifndef __SONG_H__
#define __SONG_H__

#include <string>

using std::string;

class Song {
	public: 
		string title;
		string artist;
		string genre;
		short rating;

	int getPlayCount();

	void setPlayCount(int playcount);

	int getSkipCount();

	void setSkipCount(int skipcount);

	void play();

	void skip();

	string getFilePath();

	void setFilePath(string filepath);

	int calcShuffleScore();


	private: 
		int playCount;
		int skipCount;
		time_t lastPlayTime;
		time_t lastSkipTime;
		string filePath;

	Song();
	
	~Song();

	void incrementPlayCount();
	
	void decrementPlayCount();

	void incrementSkipCount();

	void decrementSkipCount();

	time_t getLastPlayTime();

	time_t getLastSkipTime();
};

#endif
