module lab3step1(c,g,w,f);
	input c,g,w;
	output f;
	
	not(z,c);
	not(x,g);
	not(y,w);
	or(s,c,x,w);
	or(t,z,g,y);
	and(f,s,t);
		
endmodule