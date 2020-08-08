use std::env;

fn main() {
    let argv: Vec<String> = env::args().collect();
    println!("{:?}", argv);
}
