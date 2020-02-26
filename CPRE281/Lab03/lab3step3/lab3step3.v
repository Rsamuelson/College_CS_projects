module lab3step3(c,g,w,a,f);
	input c,g,w,f;
	output a;
	
	assign a =(f & ~c & ~g) | (f & ~g & ~w) | (~f & c & g) | (~ f & g & w);
	
endmodule