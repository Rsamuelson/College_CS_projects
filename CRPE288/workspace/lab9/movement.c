#include "open_interface.h"
////PART 2

//centimeters not meters
void movement(oi_t *sensor_data, int meters)
{
	int sum = 0;
	if(meters<0) //MOVING BACK
	{
		oi_setWheels(-250, -250); // move backward; full speed
		while (sum > (meters))
		{
		     oi_update(sensor_data);
			    sum += sensor_data->distance;
		 }
		oi_setWheels(0, 0); // stop

	}
	else
	{
		oi_setWheels(250, 250); //MOVE FORWARD
		while (sum < meters)
			 {

				oi_update(sensor_data);
			     sum += sensor_data->distance;

			     int colorRightFront = sensor_data->cliffFrontRightSignal;
			     int colorLeftFront = sensor_data->cliffFrontLeftSignal;
			     int colorRightSide = sensor_data->cliffRightSignal;
			     int colorLeftSide= sensor_data->cliffLeftSignal;

			     //Line Dectection (white)
			     if((colorRightFront > 2799 || colorLeftFront > 2799) && (colorRightFront < 2900 || colorLeftFront < 2900))//IF DETECT WHITE LINE
			     {
			    	 oi_setWheels(0,0);
			    	 return;
			     }

			     else if(sensor_data->cliffFrontLeft==1 | sensor_data->cliffFrontRight==1)
			     {
			    	 oi_setWheels(0,0);
			    	 timer_waitMillis(500);
			    	 movement(sensor_data, -30);
			    	 return;
			     }

			     //Line Dectection (black)
			     else if((colorRightFront > 999 || colorLeftFront > 999) && (colorRightFront < 1300 || colorLeftFront < 1300)) //IF DETECT BLACK LINE
			     {
			    	 oi_setWheels(0,0);
			    	 return;
			     }

			 }
		oi_setWheels(0, 0); // stop

	}
}


//

//NOTE sensor_data->angle

void turn(oi_t *sensor_data, int degrees)
{
	int sum = 0;
	if(degrees >0) //Counbter-Clockwise(Left)
	{
		oi_update(sensor_data);
		oi_setWheels(150, -150); // move backward; full speed

		while (sum < (degrees))
				{
				     oi_update(sensor_data);
					    sum += sensor_data->angle;
				 }
				oi_setWheels(0, 0); // stop



	}
	if(degrees<0) //Clockwise(Right)
	{
		oi_update(sensor_data);
		oi_setWheels(-150, 150); // move backward; full speed
				while (sum > (degrees))
				{
				     oi_update(sensor_data);
					    sum += sensor_data->angle;
				 }
				oi_setWheels(0, 0); // stop


	}
}




////
//////PART 3
////
void race(oi_t *sensor_data)
{
	int distance= 2000;
	oi_setWheels(500 , 500); // move forward; full speed

	int sum = 0;
	while (sum < distance)
	 {
	     oi_update(sensor_data);
	     sum += sensor_data->distance;
	     if (sensor_data->bumpLeft || sensor_data->bumpRight)
	     {

	    	 oi_setWheels(0, 0);
	    	 movement(sensor_data,-150);
	    	 sum -= 150;

	    	 turn(sensor_data,-90);
	    	 movement(sensor_data,250);
	    	 sum-=250;
	    	 turn(sensor_data,90);
	         // Respond to left bumper being pressed
	    	 oi_setWheels(500 , 500); // move forward; full speed
	     }

	 }
	  oi_setWheels(0, 0); // stop
	  oi_free(sensor_data);


}

