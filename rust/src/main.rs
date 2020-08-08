use std::env;
#[allow(unused_imports)]
use std::process::exit;

mod build;
mod create;
mod run;
mod version;

use build::{build, buildhard};
use create::create;
use run::run;
use version::{version, Version};

fn main() {
    let ver = Version {
        main: 0,
        discriminator: 1,
        third: 0,
    };
    let argv: Vec<String> = env::args().collect();
    let argc = argv.len();
    if argc < 2 {
        println!("Usage: wanager <command> [OPTIONS]");
    } else if argv[1] == "version" {
        version(ver);
    } else if argv[1] == "new" && argc == 3 {
        let ret = create(&argv[2]);
        match ret {
            Ok(()) => (),
            Err(_e) => println!("An error occured. Please retry later"),
        }
    } else if argv[1] == "build" {
        if argc == 3 && argv[2] == "release" {
            build();
        } else {
            buildhard();
        }
    } else if argv[1] == "run" {
        let ret = run();
        match ret {
            Ok(_) => (),
            Err(e) => println!("{}", e),
        }
    }
    std::process::exit(0);
}
