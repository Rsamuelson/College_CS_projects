module mux4to1(i0, i1, i2, i3, s, f);
	input i0, i1, i2, i3;
	input [1:0]s;
	output f;
	assign f = s[1] ? (s[0] ? i3 : i2) : (s[0] ? i1 : i0);
endmodule