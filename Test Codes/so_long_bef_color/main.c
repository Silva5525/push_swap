
#include <stdlib.h>
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "animate.h"
#include <string.h>

#define WIDTH 640
#define HEIGHT 360
#define BPP sizeof(int32_t)
#define SELECTION_LEN 2
#define DIFFICULTY_LEN 3
#define COLOR_SELECTION_LEN 3



void error(void) {
  puts(mlx_strerror(mlx_errno));
  exit(EXIT_FAILURE);
}

void update(void * ptr) 
{
  static int fps;
  static int menu_selection_coords[SELECTION_LEN][SELECTION_LEN] = {{256, 160}, {256, 256}};
  static int color_selection_coords[COLOR_SELECTION_LEN][2] = {{320, 256}, {416, 256}, {512, 256}};
  t_color_game* cg = (t_color_game*)ptr;

  fps = 1000 / cg->mlx->delta_time;
  printf("\e[1;1H\e[2Jfps [%d] %d\n", fps, cg->game_difficulty);
  // Clean the foreground
  memset(cg->foreground->pixels, 0xFF000000, cg->foreground->width * cg->foreground->height * BPP);
  if (cg->game_status == PLAYING) 
  {
    mlx_image_t * frame = (mlx_image_t *)ft_lstget(cg->small_select_animation->frames, cg->small_select_animation->current_frame_num)->content;
    if (!frame)
      error();

    put_img_to_img(cg->foreground, frame,
      color_selection_coords[cg->color_selection][0],
      color_selection_coords[cg->color_selection][1]);
    update_animation(cg->small_select_animation, cg->mlx->delta_time);
  } 
  else if (cg->game_status == MENU) 
  {
	if (cg->game_status == MENU) 
	{
		// Paint the select animation on the foreground
		mlx_image_t * frame = (mlx_image_t *)ft_lstget(cg->select_animation->frames, cg->select_animation->current_frame_num)->content;
		if (!frame)
		error();
		put_img_to_img(cg->foreground, frame,
		menu_selection_coords[cg->menu_selection][0],
		menu_selection_coords[cg->menu_selection][1]);
		update_animation(cg->select_animation, cg->mlx->delta_time);
		// Logic for the menu
		for (int i = 0; i < DIFFICULTY_LEN; i++) 
		{
			cg->difficulty_imgs[i]->instances[0].enabled = false;
		}
			cg->difficulty_imgs[cg->game_difficulty]->instances[0].enabled = true;
		if (mlx_is_key_down(cg->mlx, MLX_KEY_DOWN)) 
		{
			cg->menu_selection = SELECT_DIFFICULTY;
		}
		if (mlx_is_key_down(cg->mlx, MLX_KEY_UP)) 
		{
			cg->menu_selection = SELECT_PLAY;
		}
	}
	}
}

void key_update(mlx_key_data_t keydata, void* ptr) {
  t_color_game* cg = (t_color_game*)ptr;

  if (cg->game_status == PLAYING && keydata.action == MLX_PRESS) {
    if (keydata.key == MLX_KEY_LEFT) {
      cg->color_selection--;
      if (cg->color_selection == -1)
        cg->color_selection = COLOR_SELECTION_LEN - 1;
    } else if (keydata.key == MLX_KEY_RIGHT) {
      cg->color_selection++;
      cg->color_selection %= COLOR_SELECTION_LEN;
    }
  } else if (cg->game_status == MENU && keydata.action == MLX_RELEASE) {
    if (keydata.key == MLX_KEY_ENTER) 
	{
      for (int i = 0; i < DIFFICULTY_LEN; i++)
        cg->difficulty_imgs[i]->instances[0].enabled = false;
      cg->menu_bg->instances[0].enabled = false;
      cg->game_bg->instances[0].enabled = true;
      cg->game_status = PLAYING;
    }
  } 
  else if (cg->game_status == MENU && cg->menu_selection == SELECT_DIFFICULTY && keydata.action == MLX_PRESS) 
  {
    if (keydata.key == MLX_KEY_LEFT) 
	{
      cg->game_difficulty--;
      if (cg->game_difficulty == -1)
        cg->game_difficulty = DIFFICULTY_LEN - 1;
    } else if (keydata.key == MLX_KEY_RIGHT) 
	{
      cg->game_difficulty++;
      cg->game_difficulty %= DIFFICULTY_LEN;
    }
  }
}


void bait(void*ptr){(void)ptr;};

mlx_image_t * my_load_png( char* file_path, mlx_t * mlx) {
  mlx_image_t*    img;
  mlx_texture_t*  texture;
  // Try to load the file
  texture = mlx_load_png(file_path);
  if (!texture)
    error();
  // Convert texture to a displayable image
  img = mlx_texture_to_image(mlx, texture);
  if (!img)
    error();
  if (mlx_image_to_window(mlx, img, 0, 0) == -1)
    error();
  mlx_delete_texture(texture);
  return (img);
}

t_color_game init_game() {
  mlx_t*          mlx;
  mlx_image_t*    img;
  mlx_image_t*    img2;
  mlx_image_t*    foreground_img;
  mlx_image_t*    difficulty_imgs[DIFFICULTY_LEN];
  t_animation*    anim;
  t_animation*    small_anim;
  t_sprite        sprite;

  // Start mlx
  mlx = mlx_init(WIDTH, HEIGHT, "Color Game", false);
  if (!mlx)
    error();
  // Load the Background and Menu images
  img = my_load_png("./images/menu_bg.png", mlx);
  img2 = my_load_png("./images/game_bg.png", mlx);
  img2->instances[0].enabled = false; // disable game background for now
  difficulty_imgs[0] = my_load_png("./images/menu_easy.png", mlx);
  difficulty_imgs[1] = my_load_png("./images/menu_medium.png", mlx);
  difficulty_imgs[2] = my_load_png("./images/menu_hard.png", mlx);
  // Sprite & Animation
  sprite = new_sprite("./images/select_sprite_sheet.png", mlx);
  anim = slice_sprite(&sprite, (sprite_slice){0, 0, 128, 32, 0, 0}, false, 5, 120);
  destroy_sprite(&sprite);
    // Sprite & Animation (small select)
  sprite = new_sprite("./images/small_select_sprite_sheet.png", mlx);
  small_anim = slice_sprite(&sprite, (sprite_slice){0, 0, 32, 32, 0, 0}, false, 4, 120);
  destroy_sprite(&sprite);
  // Foreground
  foreground_img = mlx_new_image(mlx, WIDTH, HEIGHT);
  if (!foreground_img)
    error();
// return (t_color_game){mlx, img, img2, foreground_img,
//     {difficulty_imgs[0], difficulty_imgs[1], difficulty_imgs[2]},
//     anim, SELECT_PLAY, MENU, EASY};
return (t_color_game){mlx, img, img2, foreground_img,
    {difficulty_imgs[0], difficulty_imgs[1], difficulty_imgs[2]},
    anim, small_anim, SELECT_PLAY, MENU, EASY, RED,
    {255, 255, 255}};
}

int32_t main(void)
{
  t_color_game cg;

  cg = init_game();

	// if (mlx_image_to_window(cg.mlx, cg.menu_bg, 0, 0) == -1) (disabled for menu)
    // error();
	if (mlx_image_to_window(cg.mlx, cg.foreground, 0, 0) == -1)
    error();


  mlx_loop_hook(cg.mlx, update, &cg);
  mlx_key_hook(cg.mlx, key_update, &cg);
  mlx_loop(cg.mlx);

  ft_lstclear(&cg.select_animation->frames, bait);
  free(cg.select_animation);
  ft_lstclear(&cg.small_select_animation->frames, bait);
  free(cg.small_select_animation);
  mlx_terminate(cg.mlx);
  return (EXIT_SUCCESS);
}
