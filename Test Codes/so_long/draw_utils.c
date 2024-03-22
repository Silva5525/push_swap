#include "animate.h"

#define WIDTH 640
#define HEIGHT 360
#define GAME_TEXT_COLOR 0x424242FF

void draw_line(mlx_image_t * img, int x0, int y0, int x1, int y1, uint32_t color) {
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
        mlx_put_pixel(img, x0, y0, color);
        if (x0==x1 && y0==y1)
            break;
        e2 = err;
        if (e2 >-dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}  

static void draw_circle_coords(mlx_image_t * img, int xc, int yc, int x, int y, uint32_t color) {
    draw_line(img, xc+x, yc+y, xc-x, yc+y, color);
    draw_line(img, xc+x, yc-y, xc-x, yc-y, color);
    draw_line(img, xc+y, yc+x, xc-y, yc+x, color);
    draw_line(img, xc+y, yc-x, xc-y, yc-x, color);
}

void draw_circle(mlx_image_t * img, int xc, int yc, int r, uint32_t color) {
  int x = 0, y = r;
  int d = 3 - 2 * r;
  while (y >= x) {
    /*for each pixel we will draw all eight pixels */
    draw_circle_coords(img, xc, yc, x, y, color);
    x++;
    /*check for decision parameter and correspondingly update d, x, y*/
    if (d > 0) {
      y--;
      d = d + 4 * (x - y) + 10;
    } else {
      d = d + 4 * x + 6;
    }
    draw_circle_coords(img, xc, yc, x, y, color);
  }
}
/// @brief //------------ DINO ------------


t_dino * create_dino(char* file_path, mlx_t* mlx) {
  t_sprite sprite;
  t_animation * animation;
  t_dino* dino;

  sprite_slice slices[4] = {
    (sprite_slice){0, 0, 23, 23, 0, 0},       // IDLE [4 frames]
    (sprite_slice){47, 0, 23, 23, 0, 0},  // JUMP [4 frames]
    (sprite_slice){95, 0, 23, 23, 0, 0}, // EXPLODE [4 frames]
    (sprite_slice){143, 0, 23, 23, 0, 0}  // RUN [5 frames]
  };
  int num_frames[4] = {1, 1, 1, 1};

  dino = (t_dino *)calloc(sizeof(t_dino), 1);
  if (!dino)
    error();
  // Choose Random starting dino action
//   dino->dino_action = 1;
  // Choose random dino spawn
  dino->y = HEIGHT - 24 - (rand() % 10);
  dino->x = rand() % WIDTH;
  // Load sprite and cut all the animations
  sprite = new_sprite(file_path, mlx);
  for (int i = 0; i < 8; i++) {
    bool mirrored = i >= 4;
    animation = slice_sprite(&sprite, slices[i % 4], mirrored, num_frames[i % 4], 300);
    ft_lstadd_back(&dino->actions, ft_lstnew(animation));
  }  
  destroy_sprite(&sprite);
  return dino;
}

static void destroy_animation(void* ptr) {
  t_animation* a = (t_animation*)ptr;

  ft_lstclear(&a->frames, bait);
  free(a);
}

void destroy_dino(void* ptr) {
  t_dino * dino = (t_dino*)ptr;

  ft_lstclear(&dino->actions, destroy_animation);
  free(dino);
}

void update_dinos(void* ptr1, void* ptr2) {
  t_dino* dino = (t_dino*) ptr1;
  t_color_game* cg = (t_color_game*) ptr2;
  t_animation * action_animation;
  int dino_action_index;

  dino_action_index = (dino->dino_action - 1) + (4 * dino->mirrored);
  action_animation = (t_animation *)ft_lstget(dino->actions, dino_action_index)->content;

  mlx_image_t * frame = (mlx_image_t *)ft_lstget(action_animation->frames, action_animation->current_frame_num)->content;
  if (!frame)
    error();
  put_img_to_img(cg->foreground, frame, dino->x, dino->y);
  update_animation(action_animation, cg->mlx->delta_time);

  // Change direction 0.5% probable
  if (rand() % 1000 < 5)
    dino->mirrored = !dino->mirrored;
  // Change dino action 1% probable
  if (rand() % 100 < 1)
    dino->dino_action = 1 + (rand() % 4);
  // Update dino movement 50% probable
  if (dino->dino_action == RUNNING || dino->dino_action == JUMPING) {
    if (rand() % 2) {
      if (dino->mirrored)
        dino->x--;
      else
        dino->x++;
      if (dino->x < 0)
        // dino->x == WIDTH - 24;
      dino->x %= WIDTH;
    }
  }
}