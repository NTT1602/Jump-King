#ifndef _DEFS__H
#define _DEFS__H


const int SCREEN_WIDTH = 1000;

const int SCREEN_HEIGHT = 800;

const int totallevel = 9;

const int INITIAL_SPEED = 4.5;

const int charheight = 80;

const int charwidth = 66;

const int acceptable = 50;

const double jumph = -27.0;

const double gravmax = 12;

const int diff = 5;

const double bouncing = 10;

const double maxnonstop = 20;

const int princessx = 900;

const int princessy = 100;

const int char_clip[][4] = {
    {  0, 0, charwidth, charheight},
    { 76, 0, charwidth, charheight},
    { 152, 0, charwidth, charheight},
};
const int char_frames = sizeof(char_clip)/sizeof(int)/4;

#define WINDOW_TITLE "Jump King"

#endif
