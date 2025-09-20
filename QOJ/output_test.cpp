namespace fastwrite {
    const unsigned int S=1<<16;
    unsigned int cnt;
    char B[S+3];
    inline void write(unsigned int x) {
        if(x>9) write(x/10);
        B[cnt++]=(x%10)|48;
        if(cnt == S){
            fwrite(B,1,S,stdout);
            cnt=0;
        } 
    }
    inline void space() {
        B[cnt++]=32;
        if(cnt == S){
            fwrite(B,1,S,stdout);
            cnt=0;
        } 
    }
    inline void endl() {
        B[cnt++]=10;
        if(cnt == S){
            fwrite(B,1,S,stdout);
            cnt=0;
        } 
    }
    inline void show() {
        fwrite(B,1,cnt,stdout);
        cnt=0;
    }
}using fastwrite::write, fastwrite::space, fastwrite::show;
