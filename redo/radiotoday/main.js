(function() {

    window.addEventListener("DOMContentLoaded", () => {

        const arrayAnchors = toArray(document.querySelectorAll("a.navbar-brand"));
        const arrayNavLinks = toArray(document.querySelectorAll(".nav-link"));
        const fatButtons = toArray(document.querySelectorAll("a.btn.btn-lg.btn-primary"));
        const fullArray = [...arrayAnchors, ...arrayNavLinks, ...fatButtons];

        fullArray.forEach((el, idx, arr) => {
            el.addEventListener("click", doNotLaunch, false);
        });

    }, false);

    const doNotLaunch = (evt) => {
        evt.preventDefault();
        // alert( "It's go time!" );
    };

    const toArray = (arr) => {
        return Array.prototype.slice.call(arr);
    }

})();

/*
Optional Lab(s) 8 by Luis Artavia
draft processed on: September 23, 2023
Composed\Uploaded on: September 24, 2023
Practice document not intended for evaluation
*/