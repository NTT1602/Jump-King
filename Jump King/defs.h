#ifndef _DEFS__H
#define _DEFS__H


const int SCREEN_WIDTH = 1000;

const int SCREEN_HEIGHT = 800;

const int totallevel = 9;

const int INITIAL_SPEED = 3;

const int charheight = 100;

const int charwidth = 93;

const int acceptable = 50;

const double jumph = -27.0;

const double gravmax = 12;

const int diff = 20;

const int char_clip[][4] = {
    {  0, 0, charwidth, charheight},
    { 93, 0, charwidth, charheight},
    { 186, 0, charwidth, charheight},
};
const int char_frames = sizeof(char_clip)/sizeof(int)/4;
#define WINDOW_TITLE "Jump King"

#endif
