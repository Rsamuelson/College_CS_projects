module seven_seg_decoder (Z, Y, X ,W, A, B, C, D, E, F, G);
	input Z, Y, X, W;
	output A, B, C, D, E, F, G;
	reg A, B, C, D, E, F, G;
	always@(Z or Y or X or W)
	begin
		case({Z,Y,X,W})
			4'b0000: {A, B, C, D, E, F, G} = 7'b0000001; //0
			4'b0001: {A, B, C, D, E, F, G} = 7'b1001111; //1
			
			4'b0010: {A, B, C, D, E, F, G} = 7'b0010010; //2
			4'b0011: {A, B, C, D, E, F, G} = 7'b0000110; //3
			
			4'b0100: {A, B, C, D, E, F, G} = 7'b1001100; //4
			4'b0101: {A, B, C, D, E, F, G} = 7'b0100100; //5
			
			4'b0110: {A, B, C, D, E, F, G} = 7'b0100000; //6
			4'b0111: {A, B, C, D, E, F, G} = 7'b0001111; //7
			
			4'b1000: {A, B, C, D, E, F, G} = 7'b0000000; //8
			4'b1001: {A, B, C, D, E, F, G} = 7'b0000100; //9
			
			4'b1010: {A, B, C, D, E, F, G} = 7'b0001000; //a
			4'b1011: {A, B, C, D, E, F, G} = 7'b1100000; //b
			
			4'b1100: {A, B, C, D, E, F, G} = 7'b0110001; //c
			4'b1101: {A, B, C, D, E, F, G} = 7'b1000010; //d
			
			4'b1110: {A, B, C, D, E, F, G} = 7'b0110000; //e
			4'b1111: {A, B, C, D, E, F, G} = 7'b0111000; //f
		endcase
	end
endmodule
						