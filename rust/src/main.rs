use std::env;
#[allow(unused_imports)]
use std::process::exit;

fn main() {
    let argv: Vec<String> = env::args().collect();
    if argv.len() < 2 {
        println!("Usage: wanager <command> [OPTIONS]");
        std::process::exit(0);
    }
}
