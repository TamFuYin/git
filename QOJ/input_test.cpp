namespace fastread {
    const unsigned int S=1<<16;
    char B[S+3],*H,*T;
    inline unsigned int gc() {
        if(H==T) T=(H=B)+fread(B,1,S,stdin);
        return (H==T)?EOF:*H++;
    }
    inline unsigned int read() {
        unsigned int x,ch;
        while((ch=gc())<48);
        x=ch^'0';
        while((ch=gc())>47) x=x*10+(ch^'0');
        return x;
    }
} using fastread::read;
