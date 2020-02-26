module lab4step1(f,a,b,c,d);
	input a,b,c,d;
	output f;
	reg f;
	
	always@(a or b or c or d)
	begin
		case({d,c,b,a})
		
			4'b0000: f = 'b0;
			4'b0001: f = 'b0;
			
			4'b0010: f = 'b0;
			4'b0011: f = 'b1;
			
			4'b0100: f = 'b0;
			4'b0101: f = 'b0;
			
			4'b0110: f = 'b1;
			4'b0111: f = 'b1;
			
			4'b1000: f = 'b1;
			4'b1001: f = 'b1;
			
			4'b1010: f = 'b0;
			4'b1011: f = 'b0;
			
			4'b1100: f = 'b1;
			4'b1101: f = 'b0;
			
			4'b1110: f = 'b0;
			4'b1111: f = 'b0;
			
		endcase
		
	end
	
endmodule