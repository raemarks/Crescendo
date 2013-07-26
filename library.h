#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <string>
#include <vector>
#include "song.h"

using std::string;
using std::vector;

class Library {
	public:
	int songCount;
	int artistCount;
	int genreCount;
	int playlistCount;
	int albumCount;

	vector<Song *> songList;
//	Vector<Playlist *> playlistList;
	
	Library();

	~Library();
};

#endif
