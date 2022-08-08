/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "mononoki:size=11", "monospace:size=11" };
static const char dmenufont[]       = "mononoki:size=11";
static const char col_gray1[]       = "#191724";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#e0def4";
static const char col_main1[]       = "#eb6f92";
static const char col_main2[]       = "#31748f";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray1, col_main1,  col_main2  },
};

static const char *const autostart[] = {
        "setxkbmap", "es", NULL,
        "dwm-touchpad", NULL,
        "nitrogen", "--restore", NULL,
	"mpd", NULL,
        "dwm-status", NULL,
        "redshift", "-l", "41.39:2.16", "-m", "randr", "-t", "6200:5700", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Xviewer",  NULL,       NULL,       0,            1,           -1 },
        { "mpv",      NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY  Mod4Mask
#define SHIFT   ShiftMask
#define ALT     Mod1Mask
#define CONTROL ControlMask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* teclas raras */
#define ImprPant 0x0000ff61
#define RaiseVol 0x1008FF13
#define LowerVol 0x1008FF11
#define Mute     0x1008FF12

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_main1, "-sf", col_gray1, NULL };
static const char *termcmd[]   = { "st", NULL };
static const char *launchcmd[] = { "rofi", "-show", "drun", NULL };
static const char *filescmd[]  = { "pcmanfm", NULL };
static const char *nnncmd[]    = { "st", "-e", "zsh", "-ilc", "nnn", NULL };
static const char *browsrcmd[] = { "firefox", NULL };
static const char *vimbcmd[]   = { "tabbed", "-c", "vimb", "-e", NULL };
static const char *lockcmd[]   = { "slock", NULL };

static Key keys[] = {
	/* modifier                     key           function        argument */
	{ MODKEY,                       XK_BackSpace, spawn,          {.v = termcmd} },
	{ MODKEY,                       XK_Return,    spawn,          {.v = dmenucmd} },
	{ MODKEY|SHIFT,                 XK_Return,    spawn,          {.v = launchcmd} },

	{ MODKEY,                       XK_j,         focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,         focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,         setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,         setmfact,       {.f = +0.05} },

	{ MODKEY,                       XK_Down,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Up,        focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Left,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,     setmfact,       {.f = +0.05} },

	{ MODKEY,                       XK_i,         incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,         incnmaster,     {.i = -1 } },
	{ MODKEY|SHIFT,                 XK_b,         togglebar,      {0} },
	{ MODKEY|SHIFT,                 XK_space,     togglefullscr,  {0} },
	{ MODKEY,                       XK_space,     togglefloating, {0} },
	{ MODKEY,                       XK_z,         zoom,           {0} },
	{ MODKEY,                       XK_Tab,       view,           {0} },
	{ MODKEY|SHIFT,                 XK_Tab,       setlayout,      {0} },
	{ MODKEY,                       XK_c,         killclient,     {0} },
	{ MODKEY|SHIFT,                 XK_q,         quit,           {0} },

     /* Otros programas */
        { MODKEY,                       XK_f,         spawn,          {.v = filescmd} },
        { MODKEY,                       XK_b,         spawn,          {.v = browsrcmd} },
        { MODKEY,                       XK_v,         spawn,          {.v = vimbcmd} },
        { MODKEY,                       XK_n,         spawn,          {.v = nnncmd} },
	{ MODKEY,                       XK_Escape,    spawn,          {.v = lockcmd} },

     /* Cambiar a disposiciones especificas */
	{ MODKEY|SHIFT,                 XK_t,         setlayout,      {.v = &layouts[0]} }, /* master & stack */
	{ MODKEY|SHIFT,                 XK_f,         setlayout,      {.v = &layouts[1]} }, /* floating */
	{ MODKEY|SHIFT,                 XK_m,         setlayout,      {.v = &layouts[2]} }, /* monocle */

     /* Scripts de dmenu */
        { MODKEY|CONTROL,               XK_p,         spawn,          CMD("~/.config/dmenu/scripts/dm-pass") },
        { MODKEY|CONTROL,               XK_m,         spawn,          CMD("~/.config/dmenu/scripts/dm-mpd-select") },
        { MODKEY|CONTROL,               XK_w,         spawn,          CMD("~/.config/dmenu/scripts/dm-wifi") },
        { MODKEY|CONTROL,               XK_k,         spawn,          CMD("~/.config/dmenu/scripts/dm-kill") },
        { MODKEY|CONTROL,               XK_b,         spawn,          CMD("~/.config/dmenu/scripts/dm-bright") },

     /* Capturar pantalla o ventana activa */
        { MODKEY,                       ImprPant,     spawn,          CMD("maim ~/Imágenes/Capturas/captura_$(date +%s).png") },
        { MODKEY|ALT,                   ImprPant,     spawn,          CMD("maim -i $(xdotool getactivewindow) ~/Imágenes/Capturas/ventana_$(date +%s).png") },
        { MODKEY|SHIFT,                 ImprPant,     spawn,          CMD("maim -s ~/Imágenes/Capturas/recorte_$(date +%s).png") },
        { MODKEY|CONTROL,               ImprPant,     spawn,          CMD("maim -s | xclip -selection clipboard -t image/png") },

     /* Control del volumen global */
        { MODKEY|CONTROL,               XK_plus,      spawn,          CMD("mpc volume +5") },
        { MODKEY|CONTROL,               XK_minus,     spawn,          CMD("mpc volume -5") },
        { 0,                            RaiseVol,     spawn,          CMD("pactl set-sink-volume @DEFAULT_SINK@ +5%") },
        { 0,                            LowerVol,     spawn,          CMD("pactl set-sink-volume @DEFAULT_SINK@ -5%") },
        { 0,                            Mute,         spawn,          CMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },

     /* Cambiar entre monitores */
	{ MODKEY,                       XK_comma,     focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,    focusmon,       {.i = +1 } },
	{ MODKEY|SHIFT,                 XK_comma,     tagmon,         {.i = -1 } },
	{ MODKEY|SHIFT,                 XK_period,    tagmon,         {.i = +1 } },

     /* Gestionar tags */
	{ MODKEY,                       XK_0,         view,           {.ui = ~0 } },
	{ MODKEY|SHIFT,                 XK_0,         tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                         0)
	TAGKEYS(                        XK_2,                         1)
	TAGKEYS(                        XK_3,                         2)
	TAGKEYS(                        XK_4,                         3)
	TAGKEYS(                        XK_5,                         4)
	TAGKEYS(                        XK_6,                         5)
	TAGKEYS(                        XK_7,                         6)
	TAGKEYS(                        XK_8,                         7)
	TAGKEYS(                        XK_9,                         8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

