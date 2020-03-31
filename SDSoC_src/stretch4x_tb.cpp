/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch4x SDSoC project
 * 		File: - "stretch4x_tb.cpp"
 *
 * ----------------------------------------------------------------------------
 * Author:  David Lima (davidlimaastor@gmail.com)
 *
 *
 * TODO:
 *
 * CHANGELOG:
 *     [20-11-2018]: File cha ged to use with SDSoC
 *
 *---------------------------------------------------------------------------*/
#include "stretch4x_tb.h"

using namespace std;

class perf_counter
{
public:
     uint64_t tot, cnt, calls;
     perf_counter() : tot(0), cnt(0), calls(0) {};
     inline void reset() { tot = cnt = calls = 0; }
     inline void start() { cnt = sds_clock_counter(); calls++; };
     inline void stop() { tot += (sds_clock_counter() - cnt); };
     inline uint64_t avg_cpu_cycles() { return ((tot+(calls>>1)) / calls); };
};

void create_marks_csv(char *filename, uint64_t *hw_cycles, uint64_t *sw_cycles , int n){

	printf("\n Creating %s.csv file",filename);
	FILE *fp;
	int i = 0;
	filename=strcat(filename,".csv");
	fp=fopen(filename,"w+");
	if (fp==NULL) {fputs ("File error CSV\n",stderr); exit (1);}
	fprintf(fp,"test_number, HW, SW, SpeedUp\n");
	for(i=0;i<n;i++){
		fprintf(fp,"%d, %lu, %lu, %f\n", (i+1), hw_cycles[i], sw_cycles[i], ((double) sw_cycles[i] / (double) hw_cycles[i]) );
	}
	printf("ciao\n");
	fclose(fp);
	printf("\n %sfile created",filename);
}

/*------------------------------- Main --------------------------------------*/
int main(int argc, char** argv )
{
	uint64_t time_stamp_hw[N_REP];
	uint64_t time_stamp_sw[N_REP];
	printf("Starting measure performance project ... \n");

	perf_counter hw_ctr, sw_ctr;

    /* Errors counter */
    int c_errors = 0;

    int number_values;

    FILE *f_input;

    byte *bytes_img_in;
    byte *bytes_img_out;

    /* Pointers to images*/
    byte *check_out_sw;		// check software output
    byte *check_out_hw; 	// check hardware output

    printf("Open input.txt file ...");
    f_input = fopen("input.txt", "r");

    if (f_input==NULL) {fputs ("File error\n",stderr); exit (1);}

    printf("OK \n");

    printf("Read data from file ...");
    bytes_img_in = (byte *)malloc(64000 * sizeof(byte));
    if (bytes_img_in == NULL) {fputs ("Memory error img_in",stderr); exit (2);}

    bytes_img_out = (byte *)malloc(1228800 * sizeof(byte));
    if (bytes_img_out == NULL) {fputs ("Memory error img_out",stderr); exit (2);}

    number_values = fread (bytes_img_in, 1,64000, f_input);
    if (number_values != 64000) {fputs ("Reading error",stderr); exit (3);}
    fclose(f_input);
    printf("OK \n");


    /*----------------------------------
    ------------- Hardware -------------
    ----------------------------------*/
    printf("----------------------\n");
    printf("Executing Hardware implementation ...\n");

    printf("Calling the UUT ...");
	// start time
	
    for (int i=0; i<N_REP; i++) {
		hw_ctr.start();
/* -------------------------------- INSERT GENERATED CODE HERE ---------------------------------- */
#pragma SDS async(1)
#pragma SDS resource(1)
Stretch4x(25, 320, bytes_img_in + 0*320*sizeof(byte), bytes_img_out + 0*1280*sizeof(byte));
#pragma SDS async(2)
#pragma SDS resource(2)
Stretch4x(25, 320, bytes_img_in + 25*320*sizeof(byte), bytes_img_out + 120*1280*sizeof(byte));
#pragma SDS async(3)
#pragma SDS resource(3)
Stretch4x(25, 320, bytes_img_in + 50*320*sizeof(byte), bytes_img_out + 240*1280*sizeof(byte));
#pragma SDS async(4)
#pragma SDS resource(4)
Stretch4x(25, 320, bytes_img_in + 75*320*sizeof(byte), bytes_img_out + 360*1280*sizeof(byte));
#pragma SDS async(5)
#pragma SDS resource(5)
Stretch4x(25, 320, bytes_img_in + 100*320*sizeof(byte), bytes_img_out + 480*1280*sizeof(byte));
#pragma SDS async(6)
#pragma SDS resource(6)
Stretch4x(25, 320, bytes_img_in + 125*320*sizeof(byte), bytes_img_out + 600*1280*sizeof(byte));
#pragma SDS async(7)
#pragma SDS resource(7)
Stretch4x(25, 320, bytes_img_in + 150*320*sizeof(byte), bytes_img_out + 720*1280*sizeof(byte));
#pragma SDS async(8)
#pragma SDS resource(8)
Stretch4x(25, 320, bytes_img_in + 175*320*sizeof(byte), bytes_img_out + 840*1280*sizeof(byte));
#pragma SDS wait(1)
#pragma SDS wait(2)
#pragma SDS wait(3)
#pragma SDS wait(4)
#pragma SDS wait(5)
#pragma SDS wait(6)
#pragma SDS wait(7)
#pragma SDS wait(8)

/* -------------------------------------------------------------------------------------------- */
		hw_ctr.stop();
		time_stamp_hw[i] = hw_ctr.avg_cpu_cycles();
    }
    
    printf("OK\n");

    /*----------------------------------
    ------------- Software -------------
    ----------------------------------*/
    printf("----------------------\n");
    printf("Executing Software implementation ...\n");

    /* This is needed to move the destination pointer */
    dest_pitch = PITCH;

    /* Destination has 4 times rows and 4.8 times columns */
    dest_buffer = (byte*)malloc(SCREENWIDTH*4 * SCREENHEIGHT*4.8 \
      * 3 * sizeof(byte));

    /* Transform input in bytes */
    src_buffer = bytes_img_in;

    /* Call software */
    printf("Calling SW implementation ...");

	// start time
	
    for (int i=0; i<N_REP; i++) {
		sw_ctr.start();
		I_Stretch4x_SW(X1, Y1, X2, Y2);
		sw_ctr.stop();
		time_stamp_sw[i] = sw_ctr.avg_cpu_cycles();
    }
    // stop time

    printf("OK\n");


    /*-------------------------------------
    --------------- Check -----------------
    -------------------------------------*/
    printf("----------------------\n");
    printf("Checking results ...\n");

    /* Take pointers to check values */
    printf("Gathering images information ...");
    check_out_hw = bytes_img_out;
    check_out_sw = dest_buffer;
    printf("OK\n");

    /* Loop to check bytes */
    printf("Checking bytes in both images ... \n");

    for (int i=0; i<(1280*960); i++)
    {
        /* Check if values are different */
        if (*check_out_sw != *check_out_hw) {

            c_errors++;
            if (i<10) {
            	printf("i: %u\t HW: %u, SW: %u \n",i , *check_out_hw, *check_out_sw);
            }

        } // end if differences

        /* Next values */
        check_out_sw++;
        check_out_hw++;

    } // for I values
    printf("...\n");
    printf("OK\n");

    /* Free memory */
    free(dest_buffer);
    free(bytes_img_in);
    free(bytes_img_out);

    printf("Checking simulation result... \n");
    if (c_errors!=0)
    {
        fprintf(stdout, "-------------------------------------------\n");
        fprintf(stdout, "FAIL\n");
        fprintf(stdout, "Number of errors: %d \n", c_errors);
        fprintf(stdout, "-------------------------------------------\n");
        return 1;
    } // end if no errors
    else
    {
        fprintf(stdout, "-------------------------------------------\n");
        fprintf(stdout, "PASS\n");
        uint64_t sw_cycles = sw_ctr.avg_cpu_cycles();
        uint64_t hw_cycles = hw_ctr.avg_cpu_cycles();
        double speedup = (double) sw_cycles / (double) hw_cycles;

        std::cout << "Average number of CPU cycles running mmultadd in software: "
                  << sw_cycles << std::endl;
        std::cout << "Average number of CPU cycles running mmultadd in hardware: "
                  << hw_cycles << std::endl;
        std::cout << "Speed up: " << speedup << std::endl;
	    fprintf(stdout, "-------------------------------------------\n");
	    
	    char src[50];
	    strcpy(src,  "4hw_100");
	    create_marks_csv(src, time_stamp_hw, time_stamp_sw, N_REP);
	    
	    return 0;
    } // end if errors

}
