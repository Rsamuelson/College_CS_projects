module primeDetector(w, x, y, z, f);
	input w, x, y, z;
	output f;
	
	assign f = (~y & z & x ) | (~w & x & z) | (y & z & ~x) | (y & ~w & ~x);
	
endmodule