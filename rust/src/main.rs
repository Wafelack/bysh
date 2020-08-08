use std::env;
#[allow(unused_imports)]
use std::process::exit;

mod version;
use version::{version, Version};

fn main() {
    let ver = Version {
        main: 0,
        discriminator: 1,
        third: 0,
    };
    let argv: Vec<String> = env::args().collect();
    if argv.len() < 2 {
        println!("Usage: wanager <command> [OPTIONS]");
        std::process::exit(0);
    }
    if argv[1] == "version" {
        version(ver);
    }
}
