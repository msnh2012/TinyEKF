#include <stdlib.h>
#include <strings.h>

#define N 8
#define M 4

class TinyEKF {

    private:

        int n;
        int m;

        double * x;      // state

        double * P;   // prediction error covariance
        double * Q;   // process noise covariance
        double * R;   // measurement error covariance

        double * G;   // Kalman gain; a.k.a. K
        double * F;   // Jacobian of process model
        double * H;   // Jacobian of measurement model

        double * Ht;  // transpose of measurement Jacobian
        double * Ft;  // transpose of process Jacobian
        double * Pp;  // P, post-prediction, pre-update

        double * fx;     // f(x)
        double * hx;     // h(x)

        // temporary storage
        double * tmp1;
        double * tmp2;
        double * tmp3;
        double * tmp4;
        double * tmp5;

    protected:

        TinyEKF(int n, int m);

        ~TinyEKF();

        virtual void f(double * x, double * fx, double * F) = 0;

        virtual void h(double * fx, double * hx, double * H) = 0;    

        void set(double * A, int i, int j, double value);

    public:

        void setP(int i, int j, double value);

        void setQ(int i, int j, double value);

        void setR(int i, int j, double value);

        void setX(int i, double value);

        double getX(int i);

        void step(double * Z);
};
