use std::time::{Instant};

struct Test {
    name: String,
    amount: f64
}

fn main() {
   let tests_amount = 10;
   let mut time_total: u128 = 0;
   for i in 0..=tests_amount {
        let beg = Instant::now();       
        let mut vec = vec!();
        vec.reserve(10_000_000);
        for j in 0..vec.capacity(){
            vec.push(Test{
                name: j.to_string(),
                amount: j as f64
            });
        }

        let mut sum: f64 = 0.;
        for it in vec.iter(){
            sum += it.amount;
        }
        let elapsed = beg.elapsed().as_millis();
        time_total += elapsed;
        println!("Elapsed {} ms. Sum: {}", elapsed, sum);
   }

   let mean = time_total as f64 / tests_amount as f64;
   println!("Mean: {} ms.", mean);
}
