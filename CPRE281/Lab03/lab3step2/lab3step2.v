module lab3step2(c,g,w,f);
	input c,g,w;
	output f;
	
	assign f = (c | ~g | w)&(~c | g | ~w);
	
endmodule