/*
    Evolution Freeroam (06/05/2022 - Phoenixx X Heaven Team)
*/
#pragma warning disable 239

//General Library
#include <a_samp>
#undef MAX_PLAYERS
#define MAX_PLAYERS 50
#include <a_mysql>
#include <easyDialog>

// Password Hashing
#include <samp_bcrypt>

//YSI Library
#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_hooks>
#include <YSI_Server\y_colours>

//Server Modules
#include "modules/server/macros.inc"
#include "modules/server/variables.inc"
#include "modules/server/callbacks.inc"
#include "modules/server/connection.inc"
#include "modules/server/functions.inc"
#include "modules/server/dialogs.inc"

//Player Modules
#include "modules/player/variables.inc"
#include "modules/player/auth.inc"