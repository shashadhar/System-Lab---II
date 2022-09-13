set title "Rmin vs Price"
set xlabel "Rmin"
set ylabel "Price"
set pointsize 2
set term wxt 0
plot "<(sed -n '1,1p' gnuData_das.txt)" using 1:2 title "QB_FCF" w lp, \
"<(sed -n '2,2p' gnuData_das.txt)" using 1:2 title "QB_MCF" w lp, \
"<(sed -n '3,3p' gnuData_das.txt)" using 1:2 title "QB_SCF" w lp, \
"<(sed -n '4,4p' gnuData_das.txt)" using 1:2 title "RB_FCF" w lp, \
"<(sed -n '5,5p' gnuData_das.txt)" using 1:2 title "RB_MCF" w lp, \
"<(sed -n '6,6p' gnuData_das.txt)" using 1:2 title "RB_SCF" w lp
set term wxt 1
set title "Rmin vs Executiontime"
set xlabel "Rmin"
set ylabel "Time"
plot "<(sed -n '1,1p' gnuData_das.txt)" using 1:3 title "QB_FCF" w lp, \
"<(sed -n '2,2p' gnuData_das.txt)" using 1:3 title "QB_MCF" w lp, \
"<(sed -n '3,3p' gnuData_das.txt)" using 1:3 title "QB_SCF" w lp, \
"<(sed -n '4,4p' gnuData_das.txt)" using 1:3 title "RB_FCF" w lp, \
"<(sed -n '5,5p' gnuData_das.txt)" using 1:3 title "RB_MCF" w lp, \
"<(sed -n '6,6p' gnuData_das.txt)" using 1:3 title "RB_SCF" w lp
pause -1 "Hit any key to continue"