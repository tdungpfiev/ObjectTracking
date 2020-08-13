#include "tracking.h"


int main()
{
	Tracking testTracking;

	testTracking.LoadSequence(FILE_NAME);
	while (testTracking.LoadNextFrame() == REPLY_OK && testTracking.GetFrameNum() < 1000)
	{
		if (testTracking.GetFrameNum() == 1)
		{
			testTracking.CreateResultVideo();
		}
		testTracking.ProcessImage();
		testTracking.DetectTarget();
		testTracking.TrackTarget();
		testTracking.DisplayResult(1);
		testTracking.WriteResultVideo();
	}

	//testTracking.ReleaseResultVideo();
	
	return 0;
}
