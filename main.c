#include "uv.h"

void timer_cb(uv_timer_t* handle) {
  printf("timed up");
}

int main(int argc, char** argv) {
  uv_loop_t loop;
  uv_loop_init(&loop);
  printf("sizeof uv_loop_t %zu\n", sizeof(uv_loop_t));

  uv_timer_t timer;
  printf("sizeof uv_timer_t %zu\n", sizeof(uv_timer_t));
  uv_timer_init(&loop, &timer);
  uv_timer_start(&timer, timer_cb, 600 * 1000, FALSE);

  uv_run(&loop, UV_RUN_DEFAULT);

  uv_loop_close(&loop);
  return 0;
}
