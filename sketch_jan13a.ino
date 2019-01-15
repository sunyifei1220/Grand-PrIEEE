#define LEN 128
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x>y?y:x
#define MEDIAN(x,y,z) MIN((MAX(x,y)),z)
using namespace std;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
int * median_filter(int * raw){
  int * filtered = new int[LEN];
  for(int i = 1; i<LEN -1 ; i++){
    filtered[i] = MEDIAN(raw[i-1],raw[i],raw[i+1]);
  }
  filtered[0] = MEDIAN(raw[0],raw[0],raw[1]);
  filtered[LEN - 1] = MEDIAN(raw[LEN-2],raw[LEN-1],raw[LEN - 1]);
  raw = filtered;
  filtered = NULL;
  return raw;
}

int * gradient_filter(int * raw){
  int * filtered = new int[LEN];
  for(int i = 0; i<LEN -1 ; i++){
    filtered[i] = raw[i+1] - raw[i];
  }
  filtered[LEN -1] = 0;
  raw = filtered;
  filtered = NULL;
  return raw;
}
int * edges(int * nums){
  int maxv = nums[0], minv = nums[0];
  int maxin = 0,minin = 0;
  for(int i = 0; i<LEN ; i++){
    if(maxv <= nums[i]){
      maxv = nums[i];
      maxin = i;   
    }
    if(minv > nums[i]){
      minv = nums[i];
      minin = i;
    }
  }
  int * range = new int[2];
  range[0] = maxin;
  range[1] = minin;
  return range;
}
