module seven_segement_decoder (x3, x2, x1 ,x0, A, B, C, D, E, F, G, En);
	input x3, x2, x1, x0, En;
	output A, B, C, D, E, F, G;
	reg A, B, C, D, E, F, G;
	always@(En or x3 or x2 or x1 or x0)
	begin
		case({En,x3,x2,x1,x0})
			5'b10000: {A, B, C, D, E, F, G} = 7'b0000001; //0
			5'b10001: {A, B, C, D, E, F, G} = 7'b1001111; //1
			
			5'b10010: {A, B, C, D, E, F, G} = 7'b0010010; //2
			5'b10011: {A, B, C, D, E, F, G} = 7'b0000110; //3
			
			5'b10100: {A, B, C, D, E, F, G} = 7'b1001100; //4
			5'b10101: {A, B, C, D, E, F, G} = 7'b0100100; //5
			
			5'b10110: {A, B, C, D, E, F, G} = 7'b0100000; //6
			5'b10111: {A, B, C, D, E, F, G} = 7'b0001111; //7
			
			5'b11000: {A, B, C, D, E, F, G} = 7'b0000000; //8
			5'b11001: {A, B, C, D, E, F, G} = 7'b0000100; //9
			
			5'b11010: {A, B, C, D, E, F, G} = 7'b0001000; //a
			5'b11011: {A, B, C, D, E, F, G} = 7'b1100000; //b
			
			5'b11100: {A, B, C, D, E, F, G} = 7'b0110001; //c
			5'b11101: {A, B, C, D, E, F, G} = 7'b1000010; //d
			
			5'b11110: {A, B, C, D, E, F, G} = 7'b0110000; //e
			5'b11111: {A, B, C, D, E, F, G} = 7'b0111000; //f
			
			5'b00000: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00001: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00010: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00011: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00100: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00101: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00110: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b00111: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01000: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01001: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01010: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01011: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01100: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01101: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01110: {A, B, C, D, E, F, G} = 7'b1111111; //others
			5'b01111: {A, B, C, D, E, F, G} = 7'b1111111; //others
		endcase
	end
endmodule
		