#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
 
typedef struct{ 
 double x; 
 double y; 
 double z; 
} Vector; 
 
 
 void print_vector(const Vector v)
 {
 
 	printf("(%.2lf, %.2lf, %.2lf)",v.x,v.y,v.z);


 }
 
 Vector sum(const Vector v1, const Vector v2)
 {
 	Vector sum;
 	sum.x =v1.x+v2.x;
 	sum.y =v1.y+v2.y;
 	sum.z =v1.z+v2.z;
 	return sum;
 }
 
 Vector diff(const Vector v1, const Vector v2)
 {
 	Vector diff;
 	diff.x=v1.x-v2.x;
 	diff.y=v1.y-v2.y;
 	diff.z=v1.z-v2.z;
 	return diff;
 }
 
 Vector(multiplyby_scalar(const Vector v1, int k))
 {
 	Vector multiplyby_scalar;
 	multiplyby_scalar.x=k*v1.x;
 	multiplyby_scalar.y=k*v1.y;
 	multiplyby_scalar.z=k*v1.z;
 	return multiplyby_scalar;
 	
 }
 
 double dot_product(const Vector v1, const Vector v2)
 {
 	return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
 	
 }
 
 
 Vector(cross_product(const Vector v1, const Vector v2))
 {
 	Vector cross;
 	cross.x=(v1.y*v2.z)-(v1.z*v2.y);
 	cross.y=(v1.z*v2.x)-(v1.x*v2.z);
 	cross.z=(v1.x*v2.y)-(v1.y*v2.x);
 	return cross;
 	
 	
 }
 
 double norm(const Vector v)
 {
 
 	return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z));
 	
 }
 
 int is_unitvector(const Vector v)
 {
 	Vector v1;
 	if(norm(v1)==1)
 	return 1;
 	else return 0;
 	
 }
 
 Vector unit(const Vector v)
 {
 
 	Vector unit;
 	unit.x=v.x / norm(v);
 	unit.y=v.y / norm(v);
 	unit.z=v.z / norm(v);
 	
 	return unit;
 }


double angle(const Vector v1, const Vector v2)
{
	return acos(dot_product(v1,v2)/(norm(v1)*norm(v2)));
	
}


double distance(const Vector v1, const Vector v2)
{
	return norm(diff(v1,v2));
}


int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3)
{
	double det=(v1.x*v2.y*v3.z+v2.x*v3.y*v1.z+v3.x*v1.y*v2.z)-(v3.x*v2.y*v1.z-v1.x*v3.y*v2.z-v2.x*v1.y*v3.z);
	if(det==0) 
	return 0;
	else return 1;
}


int are_orthogonal(const Vector v1, const Vector v2, const Vector v3)
{
	if(dot_product(v1,v2)==0 && dot_product(v1,v3)==0&& dot_product(v2,v3)==0){
	
		return 1;
	}
	else return 0;
}


int are_orthonormal(const Vector v1, const Vector v2, const Vector v3)
{
	if(are_orthogonal(v1, v2, v3)==0){
		if(is_unitvector(v1)==1&& is_unitvector(v2)==1&&is_unitvector(v3)==1)
		return 1;
		
	} 
	else return 0;
}


Vector projection(const Vector v1, const Vector v2)
{
	Vector proj;
	proj.x=(dot_product(v1,v2)/(norm(v2)*norm(v2)))*v2.x;
	proj.y=(dot_product(v1,v2)/(norm(v2)*norm(v2)))*v2.y;
	proj.z=(dot_product(v1,v2)/(norm(v2)*norm(v2)))*v2.z;
	
		
	return proj;
	
}


Vector orthogonal_projection(const Vector v1, const Vector v2)
{
	Vector ortproj;
	ortproj.x=v1.x-projection(v1,v2).x;
	ortproj.y=v1.y-projection(v1,v2).y;
	ortproj.z=v1.z-projection(v1,v2).z;
	return ortproj;
	
}


int convert_2_orthogonal_basis(Vector *v1, Vector *v2, Vector *v3)
{
	Vector u1;
	Vector u2;
	Vector u3;
	
	u2=orthogonal_projection(*v2,*v1);
	*v2=u2;
	u3=diff(orthogonal_projection(*v3,*v1),projection(*v3,u2));
	*v3=u3;
	return 1;
}

char*vector2str(const Vector v)
{
	char*vector2str=(char*)malloc(30*sizeof(char));
	sprintf(vector2str,"(%.2f,%.2f,%.2f)",v.x,v.y,v.z);
	return vector2str;
	
	
}

 
	int main () 
	 
{ 
 Vector v1 = {1, 2, 2}, v2 = {-1, 0, 2}, v3 = {0, 0, 1}; 
 double k = 2; 
 
    printf(" v1 = "); 
    print_vector(v1); 
    
    printf("\n v2 = "); 
    print_vector(v2); 
    
    printf("\n v3 = "); 
    print_vector(v3); 
     
    printf("\n v1 + v2 = "); 
 	print_vector(sum(v1, v2)); 
 	
 	printf("\n v1 - v2 = ");
 	print_vector(diff(v1,v2));
 	
 	printf("\n k * v1  = "); 
 	print_vector(multiplyby_scalar(v1, k)); 
 	
 	
 	printf("\n v1 . v2 = %.2lf\n", dot_product(v1, v2)); 
 	
 	printf("v1 x v2 = "); 
 	print_vector(cross_product(v1, v2)); 
 	
 	printf("\n | v1 |  = %.2lf\n", norm(v1)); 
 	
	if(is_unitvector(v1)==1) 
    printf("v1 is a unit vector.\n"); 
	else 
  	printf("v1 is not unit vector.\n"); 
  	
  	printf("unit( v1 ) = "); 
 	print_vector(unit(v1)); 
 	
 	printf("\nangle(v1,v2)=%.2lf\n",angle(v1,v2));
 	
 	printf("distance(v1,v2)=%.2lf\n",distance(v1,v2));
 	
 	if(are_linearly_independent(v1, v2, v3)==1) 
  	printf("Vectors are linearly independent.\n"); 
  	
	else 
  	printf("Vectors are not linearly independent.\n"); 
  	
  	if(are_orthogonal(v1, v2, v3)==1) 
  	printf("Vectors are orthogonal.\n"); 
  	
	else 
  	printf("Vectors are not orthogonal.\n");  
  		
    if(are_orthonormal(v1, v2, v3)==1) 
  	printf("Vectors are orthonormal.\n"); 
  	
 	else 
  	printf("Vectors are not orthonormal.\n"); 
  
  	printf("Projection of v1 onto v2 is = "); 
 	print_vector(projection(v1, v2)); 
  	
  	printf("\nOrthogonal projection of v1 onto v2 is = "); 
 	print_vector(orthogonal_projection(v1, v2)); 
 	
 	if(convert_2_orthogonal_basis(&v1, &v2, &v3)==1){ 
  	printf("\nOrthogonalization of vectors:\n"); 
  	printf("v1 = "); 
     print_vector(v1); 
     printf("\nv2 = "); 
     print_vector(v2); 
     printf("\nv3 = "); 
     print_vector(v3); 
     printf("\n");
 }   
     
    puts(vector2str(v1)); 
    
    return 0;  
    
}
   
