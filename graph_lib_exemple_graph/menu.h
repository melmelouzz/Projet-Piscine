#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#endif // MENU_H_INCLUDED


void init()
{
    if (page) return;

    srand(time(NULL));

    /// Gestion des caractères accentués
    set_uformat(U_ASCII);

    allegro_init();
    install_timer();
    install_keyboard();
    set_keyboard_rate(0,0);
    install_mouse();

    register_png_file_type();
    jpgalleg_init();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(MODE_GRAPHIQUE,LARGEURECRAN,HAUTEURECRAN,0,0)!=0)
    {
        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
        {
            allegro_message("prb gfx mode");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    set_display_switch_mode(SWITCH_BACKGROUND);

    show_mouse(screen);

    page=create_bitmap(SCREEN_W,SCREEN_H);

    rafraichir_clavier_souris();
    buf_effacer_page();
    buf_afficher_page();

    page_frame.pos.x = 0;
    page_frame.pos.y = 0;
    page_frame.dim.x = SCREEN_W;
    page_frame.dim.y = SCREEN_H;
}
int main()
{

    // initialisation de base
    BITMAP *fond= load_bitmap("menu.bmp",NULL);
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *fond2= load_bitmap("mimi.bmp",NULL);


init();

    while(!key[KEY_ESC])
    {


        blit(fond,buffer,0,0,0,0, SCREEN_W, SCREEN_H);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);



        getpixel(fond2,mouse_x,mouse_y);
       if ( mouse_b&1 && getpixel(fond2,mouse_x,mouse_y)== makecol(255,0,0) )
            allegro_message("rouge");

       if ( mouse_b&1 && getpixel(fond2,mouse_x,mouse_y)== makecol(0,255,0) )
            allegro_message("vert"); /// a la place de vert, faire quitter

       if ( mouse_b&1 && getpixel(fond2,mouse_x,mouse_y)== makecol(0,0,255) )
            allegro_message("bleu"); /// a la place de bleu, afficher l'aide
    }


    return 0;
}
END_OF_MAIN();

