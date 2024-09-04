#![allow(dead_code)]
#![allow(unused_imports)]
#![allow(unused_must_use)]
#![allow(unused_mut)]
#![allow(unused_variables)]
use std::cmp::{max, min};
use std::mem::MaybeUninit;
use std::io::{stdin, stdout, BufRead, BufWriter, Write};
use std::collections::{HashMap, BinaryHeap, VecDeque};
use std::cmp::Reverse;

// DO NOT USE IN MULTITHREADED CONTEXT
static mut SCAN: MaybeUninit<UnsafeScanner<std::io::StdinLock<'static>>> = MaybeUninit::uninit();
fn scan<T: std::str::FromStr>() -> T { unsafe { SCAN.assume_init_mut().read() } }

fn main() {
    unsafe { SCAN.write(UnsafeScanner::new(stdin().lock())); }
    let mut out = BufWriter::new(stdout().lock());
    macro_rules! outl { ($($t:tt)*) => {{ writeln!(out, $($t)*); }}; }
    macro_rules! out { ($($t:tt)*) => {{ write!(out, $($t)*); }}; }

    let t: i32 = scan();
    for _ in 0..t {
        let n: usize = scan();
        let s: String = scan();
        let s = s.into_bytes();
        let mut res = 0;
        let mut i = 0;
        // mapie
        while i < n {
            if i + 5 <= n && &s[i..(i+5)] == b"mapie" {
                res += 1;
                i += 5;
            } else if i + 3 <= n && &s[i..(i+3)] == b"map" {
                res += 1;
                i += 3;
            } else if i + 3 <= n && &s[i..(i+3)] == b"pie" {
                res += 1;
                i += 3;
            } else {
                i += 1;
            }
        }
        outl!("{res}");
    }
}

/// https://github.com/EbTech/rust-algorithms/blob/master/src/scanner.rs
// use some unsafe for faster scanning
pub struct UnsafeScanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: std::str::SplitAsciiWhitespace<'static>,
}

impl<R: BufRead> UnsafeScanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_ascii_whitespace(),
        }
    }

    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = std::str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
    // clears the rest of the buffered line and reads the next line
    pub fn read_line(&mut self) -> Option<String> {
        self.buf_str.clear();
        self.buf_iter = "".split_ascii_whitespace();
        if self
            .reader
            .read_until(b'\n', &mut self.buf_str)
            .expect("Failed read")
            == 0
        {
            None
        } else {
            if *self.buf_str.last().unwrap() == b'\n' {
                self.buf_str.pop();
            }
            unsafe {
                Some(String::from_utf8_unchecked(std::mem::take(
                    &mut self.buf_str,
                )))
            }
        }
    }
}

pub struct BIT {
    bit: Vec<i32>,
}
impl BIT {
    pub fn new(n: usize) -> Self {
        BIT { bit: vec![0; n] }
    }
    pub fn sum(&self, mut r: i32) -> i32 {
        assert!(r >= 0 && r < self.bit.len() as i32);
        let mut res = 0;
        while r >= 0 {
            res += unsafe { self.bit.get_unchecked(r as usize) };
            r = (r & (r + 1)) - 1;
        }
        res
    }
    pub fn add(&mut self, mut index: usize, delta: i32) {
        assert!(index < self.bit.len());
        while index < self.bit.len() {
            unsafe {
                *self.bit.get_unchecked_mut(index) += delta;
            }
            index |= index + 1;
        }
    }
}

pub struct SegTree {
    s: Vec<i32>,
    n: usize,
}
impl SegTree {
    pub fn new(n: usize) -> Self {
        SegTree {
            s: vec![0; 2 * n],
            n,
        }
    }
    pub fn replace(&mut self, mut pos: usize, val: i32) {
        assert!(pos < self.n);
        unsafe {
            pos += self.n;
            *self.s.get_unchecked_mut(pos) = val;
            pos >>= 1;
            while pos != 0 {
                *self.s.get_unchecked_mut(pos) =
                    *self.s.get_unchecked(pos * 2) + *self.s.get_unchecked(pos * 2 + 1);

                pos >>= 1;
            }
        }
    }
    pub fn add(&mut self, mut pos: usize, val: i32) {
        assert!(pos < self.n);
        unsafe {
            pos += self.n;
            *self.s.get_unchecked_mut(pos) += val;
            pos >>= 1;
            while pos != 0 {
                *self.s.get_unchecked_mut(pos) =
                    *self.s.get_unchecked(pos * 2) + *self.s.get_unchecked(pos * 2 + 1);

                pos >>= 1;
            }
        }
    }
    pub fn query(&self, mut l: usize, mut r: usize) -> i32 {
        assert!(l < self.n);
        assert!(r < self.n);
        let (mut ra, mut rb) = (0, 0);
        l += self.n;
        r += self.n + 1;
        while l < r {
            if l % 2 == 1 {
                ra += unsafe { *self.s.get_unchecked(l) };
                l += 1;
            }
            if r % 2 == 1 {
                r -= 1;
                rb += unsafe { *self.s.get_unchecked(r) };
            }
            l >>= 1;
            r >>= 1;
        }
        ra + rb
    }
}

pub fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 { a } else { gcd(b, a % b) }
}
pub fn egcd(a: i64, b: i64) -> (i64, i64, i64) {
    if a == 0 {
        (b, 0, 1)
    } else {
        let (g, x, y) = egcd(b % a, a);
        (g, y - (b / a) * x, x)
    }
}
pub fn lcm(a: i64, b: i64) -> i64 {
    a / gcd(a, b) * b
}
pub fn mod_inv(a: i64, m: i64) -> Option<i64> {
    let (g, x, _) = egcd(a, m);
    if g != 1 {
        None
    } else {
        Some((x % m + m) % m)
    }
}

// returns solution x to system of congruences x \equiv a_i \mod m_i
pub fn crt(congruences: &[(i64, i64)]) -> i64 {
    let prod_m: i64 = congruences.iter().map(|c| c.1).product();

    congruences.iter().fold(0, |acc, &(a, m)| {
        let m_i = prod_m / m;
        let n_i = mod_inv(m_i, m).unwrap();
        (acc + a * m_i % prod_m * n_i) % prod_m
    })
}

#[derive(Debug, Clone)]
pub struct DSU {
    pub parent: Vec<usize>,
    pub rank: Vec<u32>,
    pub n: usize,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        DSU {
            parent: (0..n).collect(),
            rank: vec![0; n],
            n,
        }
    }
    pub fn find(&mut self, i: usize) -> usize {
        while self.parent[self.parent[i]] != self.parent[i] {
            self.parent[i] = self.parent[self.parent[i]];
        }
        self.parent[i]
    }
    pub fn union(&mut self, mut a: usize, mut b: usize) -> bool {
        a = self.find(a);
        b = self.find(b);
        if a == b { return false; }
        if self.rank[a] < self.rank[b] {
            std::mem::swap(&mut a, &mut b);
        }
        self.parent[b] = a;
        if self.rank[a] == self.rank[b] {
            self.rank[a] += 1;
        }
        true
    }
}

trait Z {
    fn z(&self) -> Vec<usize>;
}
impl Z for &[u8] {
    fn z(&self) -> Vec<usize> {
        let n = self.len();
        let mut z = vec![0; n];
        let (mut l, mut r) = (0, 0);
        for i in 1..n {
            if i < r {
                z[i] = min(r - i, z[i - l]);
            }
            while i + z[i] < n && self[z[i]] == self[i + z[i]] {
                z[i] += 1;
            }
            if i + z[i] > r {
                l = i;
                r = i + z[i];
            }
        }
        z
    }
}
impl Z for String {
    fn z(&self) -> Vec<usize> {
        self.as_bytes().z()
    }
}

// copy paste from rustc-hash crate
use std::mem::size_of;
use std::convert::TryInto;
use std::ops::BitXor;
#[derive(Clone)]
pub struct FxHasher {
    hash: usize,
}

#[cfg(target_pointer_width = "32")]
const K: usize = 0x9e3779b9;
#[cfg(target_pointer_width = "64")]
const K: usize = 0x517cc1b727220a95;

#[inline]
fn take_first_chunk<'a, const N: usize>(slice: &mut &'a [u8]) -> Option<&'a [u8; N]> {
    if slice.len() < N {
        return None;
    }
    let (first, rest) = slice.split_at(N);
    *slice = rest;
    Some(first.try_into().unwrap())
}

impl FxHasher {
    pub const fn with_seed(seed: usize) -> FxHasher {
        FxHasher { hash: seed }
    }
    pub const fn default() -> FxHasher {
        FxHasher { hash: 0 }
    }
}

impl Default for FxHasher {
    #[inline]
    fn default() -> FxHasher {
        Self::default()
    }
}

impl FxHasher {
    #[inline]
    fn add_to_hash(&mut self, i: usize) {
        self.hash = self.hash.rotate_left(5).bitxor(i).wrapping_mul(K);
    }
}

impl std::hash::Hasher for FxHasher {
    #[inline]
    fn write(&mut self, mut bytes: &[u8]) {
        const _: () = assert!(size_of::<usize>() <= size_of::<u64>());
        const _: () = assert!(size_of::<u32>() <= size_of::<usize>());
        let mut state = self.clone();
        while let Some(&usize_bytes) = take_first_chunk(&mut bytes) {
            state.add_to_hash(usize::from_ne_bytes(usize_bytes));
        }
        if let Some(&u32_bytes) = take_first_chunk(&mut bytes) {
            state.add_to_hash(u32::from_ne_bytes(u32_bytes) as usize);
        }
        if let Some(&u16_bytes) = take_first_chunk(&mut bytes) {
            state.add_to_hash(u16::from_ne_bytes(u16_bytes) as usize);
        }
        if let Some(&[u8_byte]) = take_first_chunk(&mut bytes) {
            state.add_to_hash(u8_byte as usize);
        }
        *self = state;
    }

    #[inline]
    fn finish(&self) -> u64 {
        self.hash as u64
    }
}

use std::hash::{BuildHasherDefault, Hash};
use std::ops::{Deref, DerefMut, Index, IndexMut};
#[derive(Default, Debug, Clone, Eq, PartialEq)]
struct Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    hm: HashMap<K, V, BuildHasherDefault<FxHasher>>,
}
impl<K, V> Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    fn new() -> Self {
        Self {
            hm: HashMap::<K, V, BuildHasherDefault<FxHasher>>::default(),
        }
    }
}

impl<K, V> Index<&K> for Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    type Output = V;
    // panic if item not in map, cannot mutate map to return reference to default
    fn index(&self, key: &K) -> &Self::Output {
        &self.hm[key]
    }
}

impl<K, V> Index<K> for Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    type Output = V;
    // panic if item not in map, cannot mutate map to return reference to default
    fn index(&self, key: K) -> &Self::Output {
        &self.hm[&key]
    }
}

impl<K, V> IndexMut<K> for Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    fn index_mut(&mut self, key: K) -> &mut V {
        self.hm.entry(key).or_default()
    }
}

// antipattern
impl<K, V> Deref for Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    type Target = HashMap<K, V, BuildHasherDefault<FxHasher>>;
    fn deref(&self) -> &Self::Target {
        &self.hm
    }
}
impl<K, V> DerefMut for Map<K, V>
where
    K: Eq + PartialEq + Hash,
    V: Default,
{
    fn deref_mut(&mut self) -> &mut Self::Target {
        &mut self.hm
    }
}
