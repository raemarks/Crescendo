#include "song.h"
#include <iostream>
#include <string>
#include <ctime>

using std::string;

Song::Song () {
	playCount = 0;
	skipCount = 0;
	lastPlayTime = 0;
	lastSkipTime = 0;
	filePath = "";
}

Song::~Song() {}

int Song::getPlayCount() {
	return playCount;
}

void Song::setPlayCount(int playcount) {
	playCount = playcount;
}

void Song::incrementPlayCount() {
	playCount++;
}

void Song::decrementPlayCount() {
	playCount--;
}

int Song::getSkipCount() {
	return skipCount;
}

void Song::setSkipCount(int skipcount) {
	skipCount = skipcount;
}

void Song::incrementSkipCount() {
	skipCount++;
}

void Song::decrementSkipCount() {
	skipCount--;
}

time_t Song::getLastSkipTime() {
	return lastSkipTime;
}

time_t Song::getLastPlayTime() {
	return lastPlayTime;
}

string Song::getFilePath() {
	return filePath;
}

void Song::setFilePath(string filepath) {
	filePath = filepath;
}

void Song::play() {
	incrementPlayCount();
	lastPlayTime = time(0);
	//do more here
}

void Song::skip() {
	decrementSkipCount();
	incrementPlayCount();
	lastSkipTime = time(0);
	//do more here
}

int Song::calcShuffleScore() {
	int score = 0;
	//math stuff here
	return score;
}


