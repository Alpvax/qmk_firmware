#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define MASTER_LEFT

// custom transport for displaying master version on both side
// #define SPLIT_TRANSACTION_IDS_USER USER_SYNC_VER

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_LINUX
