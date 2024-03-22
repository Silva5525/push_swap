#ifndef __ANIMATIONS_H__
# define __ANIMATIONS_H__

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define DIFFICULTY_LEN 3
#define BPP sizeof(int32_t)
#define SELECTION_LEN 2
#define DIFFICULTY_LEN 3
#define COLOR_SELECTION_LEN 3


/// @brief ///////////////  DINO  /////////////////////////

enum dino_action {
  IDLE = 1,
  RUNNING = 2,
  EXPLODING = 3,
  JUMPING = 4
};

typedef struct s_dino {
  int x;
  int y;
  enum dino_action dino_action;
  bool mirrored;
  t_list * actions; //  List of all the dino actions, 8 total animations
} t_dino;


////-----------------  ANIMATIONS  -----------------////

enum color_selection {
  RED,
  GREEN,
  BLUE
};

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

enum game_status {
  MENU,
  PLAYING,
  SCORE
};

enum menu_selection {
  SELECT_PLAY,
  SELECT_DIFFICULTY
};

enum game_difficulty {
  EASY,
  MEDIUM,
  HARD
};

typedef struct s_animation {
  t_list*   frames;
  int       frame_speed;        // The speed of the animation in miliseconds
  double    accum;              // The accumulator to controll the speed
  int       current_frame_num;  // Which frame is selected
  int       mirrored;
  long int  updated_at;         // When was the last update
  long int  frame_count;        // The frame count
} t_animation;

typedef struct sprite_slice {
  int x;
  int y;
  int width;
  int height;
  int padding_x;
  int padding_y;
} sprite_slice;

typedef struct s_sprite {
  mlx_image_t*  sprite_img;
  mlx_t*        mlx;
//   mlx_image_t*    foreground_img;
} t_sprite;

typedef struct s_color_game {
  mlx_t* mlx;
  mlx_image_t* menu_bg;
  mlx_image_t* game_bg;
  mlx_image_t* score_bg;
  mlx_image_t* foreground;
  mlx_image_t* lock_img;
  mlx_image_t* difficulty_imgs[DIFFICULTY_LEN];
  t_animation* select_animation;
  t_animation* small_select_animation;
  t_animation* star_animation;
  t_list*      random_dinos;
  enum menu_selection menu_selection;
  enum game_status game_status;
  enum game_difficulty game_difficulty;
  enum color_selection color_selection;
  int selected_colors[COLOR_SELECTION_LEN];
  int game_colors[COLOR_SELECTION_LEN];
  int score;
} t_color_game;


// test_main.c
void error(void);
t_color_game init_game();
void update(void * ptr);
void bait(void*ptr);

/// image_utils.c
int get_rgba(int r, int g, int b, int a);
int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y);
// static int put_pixel_valid(mlx_image_t* img, uint32_t x, uint32_t y);
void  put_img_to_img(mlx_image_t* dst, mlx_image_t* src, int x, int y);
// void	ft_lstclear(t_list **lst, void (*del)(void*));
// void	ft_lstadd_back(t_list **lst, t_list *new);
// t_list	*ft_lstnew(void *content);
// int	ft_lstsize(t_list *lst);
// void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr);
void my_mlx_put_string(char * str, t_color_game * cg, int x, int y);

// static int get_rgba(int r, int g, int b, int a);
int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y);
void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr);
t_list		*ft_lstget(t_list *lst, int index);
/// animte.c
void error(void);
void update_animation(t_animation * a, double dt);
t_sprite new_sprite(char* file_path, mlx_t* mlx);
void    destroy_sprite(t_sprite* s);
// static void add_frame(t_animation* a, t_sprite* s, sprite_slice slice, int mirrored);
t_animation* slice_sprite(t_sprite* s, sprite_slice slice, int mirrored, int frames, int delay);

// draw_utils.c
void draw_line(mlx_image_t * img, int x0, int y0, int x1, int y1, uint32_t color);
// static void draw_circle_coords(mlx_image_t * img, int xc, int yc, int x, int y, uint32_t color);
void draw_circle(mlx_image_t * img, int xc, int yc, int r, uint32_t color);
// static int colors_diff(int r1, int g1, int b1, int r2, int g2, int b2);
// static double colors_dist(int r1, int g1, int b1, int r2, int g2, int b2);


void destroy_dino(void* ptr);
// static void destroy_animation(void* ptr);
t_dino * create_dino(char* file_path, mlx_t* mlx);
void update_dinos(void* ptr1, void* ptr2);

#endif