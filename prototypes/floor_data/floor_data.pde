final int near_z = 256;
final int far_z = 64;
final int stripe = 16;

final int shift = 4;
final int WIDTH = 320;
final int HEIGHT = 256;
final int PART = HEIGHT / 2;

void settings() {
  size(WIDTH + 16, HEIGHT + 1);
  noSmooth();
}

void setup() {
  int near_w = stripe * near_z / 256;
  int far_w = stripe * far_z / 256;
  
  background(0);
  loadPixels();
  
  int line = 0;
  
  for (int y = 0; y < PART; y++, line += width) {
    int stripe_w = far_w << shift;
    // int start = (y - PART) + stripe_w * 15;
    int start = (int)(stripe_w * 0.25 * (1.0 - sin(y * 4 * PI / PART))) + stripe_w * 11 / 16;

    for (int x = 0; x < width; x++) {
      int stripe = (start + x << shift) / stripe_w; 
      int c = (stripe % 15 + 1) * 8 + 128;
      pixels[line + x] = color(c, c, c);
    }
  }
  
  for (int y = 0; y < PART; y++, line += width) {
    int stripe_w = (far_w << shift) + ((y << shift) * (near_w - far_w) / PART);
    int start = 0;
    
    for (int x = 0; x < width; x++) {
      int stripe = start + (x << shift) / stripe_w; 
      int c = (stripe % 15 + 1) * 8 + 128;
      pixels[line + x] = color(c, c, c);
    }
  }
  
  updatePixels();
 
  save("floor.png");
}
