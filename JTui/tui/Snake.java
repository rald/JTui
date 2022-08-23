class Snake {

	static Tui tui = new Tui();

	static int key;

	static boolean quit=false;

	static int LEN_MAX=100;
	static int len=1;

	static int[] x=new int[LEN_MAX];
	static int[] y=new int[LEN_MAX];
	static int xi=1,yi=0;
	static int fx=0,fy=0;
	static int i=0,j=-1;
	
	static boolean again=false;
	
	static void food() {
		int nfx=(int)Math.floor(Math.random()*tui.getWidth())+1;
		int nfy=(int)Math.floor(Math.random()*(tui.getHeight()-1))+1;
		
		fx=nfx; fy=nfy;
	
		do {		
			again=false;
			for(i=0;i<len;i++) {
				if(fx==x[i] && fy==y[i]) {
					fx++;
					if(fx>tui.getWidth()) {
						fx=1;
						fy++;
						if(fy>tui.getHeight()-1) {
							fy=1;
						}
					}
					if(fx==nfx && fy==nfy) System.exit(1);
					again=true;
					break;
				}
			}		
		} while(again);		
		
		tui.gotoxy(fx,fy);
		System.out.print('O');      
	}

	public static void main(String[] args) {

		tui.setWindow(1,1,20,20,true);

    tui.hideCursor();
		tui.clrscr();

		x[0]=1; y[0]=1;
		
		food();

    while(!quit) {
      tui.gotoxy(x[0],y[0]); System.out.print('X');

			if(fx==x[0] && fy==y[0]) {
				len++;
				food();
			}

			if(j==-1) {
				for(i=len;i>0;i--) {
					x[i]=x[i-1];
					y[i]=y[i-1];
				}
				tui.gotoxy(x[len],y[len]);
				System.out.print(' ');
      }

      if(tui.kbhit()!=0) {
        key=tui.getch();
        switch(key) {
          case 27: quit=true; break;
          case 'w': if(yi!= 1) { xi= 0; yi=-1; } break;
          case 's': if(yi!=-1) { xi= 0; yi= 1; } break;
          case 'a': if(xi!= 1) { xi=-1; yi= 0; } break;
          case 'd': if(xi!=-1) { xi= 1; yi= 0; } break;
          default: break;
        }
      }
			
			j=-1;
			for(i=0;i<len;i++) {
				if(x[0]+xi==x[i] && y[0]+yi==y[i]) {
					j=i;
					break;
				}
			}
			
			if(j==-1) {
				x[0]+=xi;
				y[0]+=yi;
      }

      if(x[0]<1)  x[0]=tui.getWidth();
      if(y[0]<1)  y[0]=tui.getHeight()-1;
      if(x[0]>tui.getWidth()) x[0]=1;
      if(y[0]>tui.getHeight()-1) y[0]=1;

    }

		tui.setWindow(1,1,80,25,true);
		tui.showCursor();
		tui.clrscr();

    
	}
}
