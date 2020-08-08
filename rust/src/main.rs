use std::env;
#[allow(unused_imports)]
use std::process::exit;

mod create;
mod version;

use create::create;
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
        std::process::exit(0);
    }
    if argv[1] == "new" && argv.len() == 3 {
        let ret = create(&argv[2]);
        match ret {
            Ok(()) => (),
            Err(_e) => println!("An error occured. Please retry later"),
        }
        std::process::exit(0);
    }
}
