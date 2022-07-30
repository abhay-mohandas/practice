use std::io::stdin;

fn main(){
    println!("To find the area and parameter of rectangle, provide the following details:");
    println!("Lenght:");
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed to read input!\n");
    let lenght:f64 = input.trim().parse().unwrap();
    println!("Breadth:");
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed to read input!\n");
    let breadth:f64 = input.trim().parse().unwrap();
    let area = lenght*breadth;
    let parameter = (2.0*lenght)+(2.0*breadth);
    println!("Result:");
    println!("Area = {} \nParameter = {}",area,parameter);
}

