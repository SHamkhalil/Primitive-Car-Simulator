double sim_answer() { return 42.0; }

double speedConvertKPHtoMPS(double speedInKPH){ 
  if (speedInKPH < 0) return -1;
  return (speedInKPH * 10) / 36; 
}