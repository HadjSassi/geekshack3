(this["webpackJsonpgeeks-teams"] = this["webpackJsonpgeeks-teams"] || []).push([[0], {
    35: function (e, t, a) {
    }, 36: function (e, t, a) {
    }, 68: function (e, t, a) {
        "use strict";
        a.r(t);
        var n = a(1), c = a.n(n), s = a(15), r = a.n(s), o = (a(35), a(11)), i = a(2),
            u = (a(36), a.p + "static/media/chart.8adefed0.png"), l = a(28), d = a(30), j = a(29), b = a.n(j), p = a(5),
            h = a.n(p), O = a(0);
        var m = function () {
            var e = Object(n.useState)([""]), t = Object(i.a)(e, 2), a = (t[0], t[1], Object(n.useState)(!1)),
                c = Object(i.a)(a, 2), s = c[0], r = c[1], j = Object(n.useState)(), p = Object(i.a)(j, 2), m = p[0],
                g = p[1], f = Object(n.useState)(!1), x = Object(i.a)(f, 2), v = (x[0], x[1]),
                y = Object(n.useState)(!1), w = Object(i.a)(y, 2), S = w[0], k = w[1], N = Object(n.useState)(""),
                C = Object(i.a)(N, 2), D = C[0], T = C[1], _ = Object(n.useState)(""), F = Object(i.a)(_, 2), L = F[0],
                E = F[1], M = Object(n.useState)(""), A = Object(i.a)(M, 2), R = A[0], I = A[1],
                P = Object(n.useState)(""), z = Object(i.a)(P, 2), B = z[0], Y = z[1], q = Object(n.useState)(""),
                J = Object(i.a)(q, 2), H = J[0], U = J[1], Z = Object(n.useState)(""), G = Object(i.a)(Z, 2),
                K = (G[0], G[1], Object(n.useState)("")), Q = Object(i.a)(K, 2), V = Q[0], W = Q[1],
                X = Object(n.useState)("green"), $ = Object(i.a)(X, 2), ee = $[0], te = $[1],
                ae = Object(n.useState)(""), ne = Object(i.a)(ae, 2), ce = ne[0], se = ne[1],
                re = Object(n.useState)(""), oe = Object(i.a)(re, 2), ie = oe[0], ue = oe[1],
                le = Object(n.useState)(!0), de = Object(i.a)(le, 2), je = de[0], be = de[1],
                pe = Object(n.useState)(!0), he = Object(i.a)(pe, 2), Oe = he[0], me = he[1],
                ge = Object(n.useState)(0), fe = Object(i.a)(ge, 2), xe = fe[0], ve = fe[1], ye = Object(n.useState)(0),
                we = Object(i.a)(ye, 2), Se = we[0], ke = we[1], Ne = Object(n.useState)(""), Ce = Object(i.a)(Ne, 2),
                De = Ce[0], Te = Ce[1], _e = Object(n.useState)(""), Fe = Object(i.a)(_e, 2), Le = Fe[0], Ee = Fe[1],
                Me = Object(n.useState)([!1, !0, !0]), Ae = Object(i.a)(Me, 2), Re = Ae[0], Ie = Ae[1],
                Pe = Object(n.useState)(""), ze = Object(i.a)(Pe, 2), Be = (ze[0], ze[1], function (e) {
                    var t = Object(o.a)(Re);
                    t[e] = !0, t[e + 1] = !1, Ie(t)
                }), Ye = function (e) {
                    var t = Object(o.a)(Re);
                    t[e] = !0, t[e - 1] = !1, Ie(t)
                }, qe = Object(n.useState)(!1), Je = Object(i.a)(qe, 2), He = Je[0], Ue = Je[1],
                Ze = Object(n.useState)(""), Ge = Object(i.a)(Ze, 2), Ke = Ge[0], Qe = Ge[1],
                Ve = Object(n.useState)(""), We = Object(i.a)(Ve, 2), Xe = We[0], $e = We[1],
                et = Object(n.useState)(""), tt = Object(i.a)(et, 2), at = tt[0], nt = tt[1],
                ct = Object(n.useState)(""), st = Object(i.a)(ct, 2), rt = st[0], ot = st[1],
                it = Object(n.useState)(""), ut = Object(i.a)(it, 2), lt = ut[0], dt = ut[1],
                jt = Object(n.useRef)(null), bt = Object(n.useState)("00:00:00"), pt = Object(i.a)(bt, 2), ht = pt[0],
                Ot = pt[1], mt = function (e) {
                    var t = function (e) {
                        var t = Date.parse(e) - Date.parse(new Date), a = Math.floor(t / 1e3 % 60),
                            n = Math.floor(t / 1e3 / 60 % 60);
                        return {total: t, hours: Math.floor(t / 1e3 * 60 * 60 % 24), minutes: n, seconds: a}
                    }(e), a = t.total, n = (t.hours, t.minutes), c = t.seconds;
                    a >= 0 && Ot((n > 9 ? n : "0" + n) + ":" + (c > 9 ? c : "0" + c))
                };
            return Object(n.useEffect)((function () {
                !function (e) {
                    Ot("30:00"), jt.current && clearInterval(jt.current);
                    var t = setInterval((function () {
                        mt(e)
                    }), 1e3);
                    jt.current = t
                }(function () {
                    var e = new Date;
                    return e.setSeconds(e.getSeconds() + 1800), e
                }())
            }), []), "00:00" == ht && window.location.reload(), Object(O.jsx)("div", {
                className: "screen", children: Object(O.jsxs)("div", {
                    className: "container", children: [Object(O.jsx)("img", {src: u}), Object(O.jsxs)(b.a, {
                        isOpen: S, onAfterOpen: function () {
                            k(!0)
                        }, onRequestClose: function () {
                            k(!1), r(!1)
                        }, style: {
                            content: {
                                top: "50%",
                                left: "50%",
                                right: "auto",
                                bottom: "auto",
                                marginRight: "-50%",
                                transform: "translate(-50%, -50%)",
                                alignContent: "center",
                                borderRadius: "4%",
                                paddingTop: "0",
                                paddingBottom: "2%",
                                backgroundColor: B,
                                zIndex: 100
                            }
                        }, ariaHideApp: !1, contentLabel: "Alert", children: [Object(O.jsx)("h2", {
                            style: {color: R}, children: L
                        }), Object(O.jsx)("div", {
                            style: {margin: "0 auto", fontSize: "16px", color: "white"}, children: D
                        })]
                    }), Object(O.jsx)("form", {
                        onSubmit: function (e) {
                            if (e.preventDefault(), r(!0), "" !== H && "" !== Xe && m) {
                                var t = new FormData;
                                t.append("team_tag", H), t.append("leader_username", Xe), t.append("member_one_username", De), t.append("member_two_username", Le), t.append("preuve", m), h.a.post("https://geekshack.ensitgeeksclub.com/paiement.php", t).then((function (e) {
                                    r(!1), 200 == e.status && (Y("#41d888"), k(!0), T(e.data), I("white"), E("Success")), e.status >= 201 && (Y("#f94416"), k(!0), T(e.data), I("white"), E("Error"))
                                })).catch((function (e) {
                                    Y("#f94416"), k(!0), T("Server error"), I("white"), E("Error")
                                }))
                            } else Y("#f94416"), k(!0), T("Please make sure to type all team informations !"), I("white"), E("Error")
                        }, children: Object(O.jsxs)("div", {
                            className: "row", children: [Object(O.jsxs)("div", {
                                style: {margin: "0 auto", width: "100%"}, children: [Object(O.jsxs)("h2", {
                                    style: {textAlign: "center"},
                                    children: ["Team Registration Form", Object(O.jsx)("br", {})]
                                }), Object(O.jsxs)("h3", {
                                    style: {textAlign: "center", color: "#1c83d1"}, children: [""]
                                })]
                            }), Object(O.jsxs)("div", {
                                hidden: Re[0], children: [Object(O.jsx)("input", {
                                    className: "input-group.input-group-icon",
                                    type: "text",
                                    placeholder: "Team name",
                                    name: "teamName",
                                    onChange: function (e) {
                                        !function (e) {
                                            if (/[^a-zA-Z0-9_]/.test(e.target.value)) W("Team tag must contain letters and numbers only !!"), te("red"); else if (5 <= e.target.value.length && e.target.value.length <= 15) {
                                                U(e.target.value);
                                                var t = new FormData;
                                                t.append("team_tag", e.target.value), h.a.post("https://geekshack.ensitgeeksclub.com/teamname.php", t).then((function (e) {
                                                    r(!1), 200 == e.status && (be(!1), W(e.data), te("green")), e.status >= 201 && (W(e.data), be(!0), te("red"))
                                                })).catch((function (e) {
                                                    Y("#f94416"), k(!0), T("Server error"), I("white"), E("Error")
                                                }))
                                            } else W("Team tag length must contain at least 5 characters !!"), te("red")
                                        }(e)
                                    }
                                }), Object(O.jsx)("p", {
                                    style: {color: ee, paddingLeft: "1em"}, children: V
                                }), Object(O.jsx)("input", {
                                    className: "input-group.input-group-icon",
                                    type: "text",
                                    placeholder: "Leader username",
                                    name: "leader",
                                    onChange: function (e) {
                                        !function (e) {
                                            $e(e.target.value);
                                            var t = new FormData;
                                            t.append("leader_username", e.target.value), h.a.post("https://geekshack.ensitgeeksclub.com/leader.php", t).then((function (e) {
                                                r(!1), 200 == e.status && (me(!1), Qe(e.data), nt("green")), e.status >= 201 && (Qe(e.data), me(!0), nt("red"))
                                            })).catch((function (e) {
                                                Y("#f94416"), k(!0), T("Server error"), I("white"), E("Error")
                                            }))
                                        }(e)
                                    }
                                }), Object(O.jsx)("p", {
                                    style: {color: at, paddingLeft: "1em"}, children: Ke
                                }), Object(O.jsx)("input", {
                                    type: "button", value: "Next", className: "btn", onClick: function () {
                                        Be(0)
                                    }, style: {padding: "5px", height: "40px", marginTop: "1%"}, disabled: Oe || je
                                })]
                            }), Object(O.jsxs)("div", {
                                hidden: Re[1], children: [Object(O.jsx)("label", {
                                    className: "doc",
                                    style: {padding: "0", margin: "1%", marginTop: "0", display: "flex"},
                                    children: Object(O.jsx)("div", {
                                        style: {width: "90%"}, children: Object(O.jsx)("input", {
                                            style: {margin: "0", border: "none"},
                                            type: "text",
                                            name: "Member_one",
                                            placeholder: "Member_one",
                                            onChange: function (e) {
                                                !function (e) {
                                                    if ("" != e.target.value) if (Te(e.target.value), e.target.value == Le) ue("Don't use the same username twice"), ot("red"), Ue(!0), ve(0); else if (e.target.value != Xe) {
                                                        var t = new FormData;
                                                        t.append("username", e.target.value), h.a.post("https://geekshack.ensitgeeksclub.com/member.php", t).then((function (e) {
                                                            r(!1), 200 == e.status && (me(!1), ue(e.data), ot("green"), Ue(!1), ve(25)), e.status >= 201 && (ue(e.data), me(!0), ot("red"), Ue(!0), ve(0))
                                                        })).catch((function (e) {
                                                            Y("#f94416"), k(!0), T("Server error"), I("white"), E("Error"), Ue(!0), ve(0)
                                                        }))
                                                    } else se("Not allowed to use leader username"), Ue(!0), ve(0); else Te(""), ue(""), Ue(!1), ve(0)
                                                }(e)
                                            }
                                        })
                                    })
                                }), Object(O.jsx)("p", {
                                    style: {color: rt, paddingLeft: "1em"}, children: ie
                                }), Object(O.jsx)("label", {
                                    className: "doc",
                                    style: {padding: "0", margin: "1%", marginTop: "0", display: "flex"},
                                    children: Object(O.jsx)("div", {
                                        style: {width: "90%"}, children: Object(O.jsx)("input", {
                                            style: {margin: "0", border: "none"},
                                            type: "text",
                                            name: "Member_two",
                                            placeholder: "Member_two",
                                            onChange: function (e) {
                                                !function (e) {
                                                    if ("" != e.target.value) if (e.target.value == De) se("Don't use the same username twice"), dt("red"), Ue(!0), ke(0); else if (e.target.value != Xe) {
                                                        Ee(e.target.value);
                                                        var t = new FormData;
                                                        t.append("username", e.target.value), h.a.post("https://geekshack.ensitgeeksclub.com/member.php", t).then((function (e) {
                                                            r(!1), 200 == e.status && (se(e.data), dt("green"), Ue(!1), ke(25)), e.status >= 201 && (se(e.data), dt("red"), Ue(!0), ke(0))
                                                        })).catch((function (e) {
                                                            Y("#f94416"), k(!0), T("Server error"), I("white"), E("Error"), Ue(!0), ke(0)
                                                        }))
                                                    } else se("Not allowed to use leader username"), nt("red"), Ue(!0), ke(0); else Ee(""), se(""), Ue(!1), ke(0)
                                                }(e)
                                            }
                                        })
                                    })
                                }), Object(O.jsx)("p", {
                                    style: {color: lt, paddingLeft: "1em"}, children: ce
                                }), Object(O.jsxs)("div", {
                                    className: "btc", children: [Object(O.jsx)("p", {
                                        style: {color: "#1c83d1", paddingLeft: "1em"},
                                        children: Object(O.jsx)("strong", {children: ""})
                                    }), Object(O.jsx)("input", {
                                        type: "button", value: "Previous", className: "btn", onClick: function () {
                                            Ye(1)
                                        }, style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    }), Object(O.jsx)("input", {
                                        type: "button",
                                        value: "Next",
                                        disabled: He,
                                        className: "btn",
                                        onClick: function () {
                                            Be(1)
                                        },
                                        style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    })]
                                })]
                            }), Object(O.jsxs)("div", {
                                hidden: Re[2], children: [Object(O.jsx)("p", {
                                    style: {paddingLeft: "2%"},
                                    children: Object(O.jsx)("strong", {children: "*Make sure to provide us with a photo of your payment receipt"})
                                }), Object(O.jsxs)("p", {
                                    style: {paddingLeft: "2%", color: "#1c83d1"},
                                    children: ["*You have to pay ", Object(O.jsxs)("strong", {children: [25 + xe + Se, " DT"]}), " by money transfer through ", Object(O.jsx)("strong", {children: "D17"}), " app ", Object(O.jsx)("strong", {children: "53417866"})]
                                }), Object(O.jsxs)("label", {
                                    className: "doc", children: [Object(O.jsx)(l.a, {
                                        icon: d.a, style: {paddingRight: "1%"}
                                    }), m ? m.name : "Upload your document", Object(O.jsx)("input", {
                                        className: "input-group.input-group-icon",
                                        hidden: !0,
                                        type: "file",
                                        placeholder: "preuve",
                                        name: "preuve",
                                        onChange: function (e) {
                                            g(e.target.files[0]), v(!0)
                                        }
                                    })]
                                }), Object(O.jsx)("br", {}), s ? Object(O.jsx)("div", {
                                    style: {margin: "0 auto"}, className: "loader"
                                }) : Object(O.jsxs)(O.Fragment, {
                                    children: [Object(O.jsx)("input", {
                                        type: "button", value: "Previous", className: "btn", onClick: function () {
                                            Ye(2)
                                        }, style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    }), Object(O.jsx)("input", {
                                        value: "Submit",
                                        type: "submit",
                                        className: "btn",
                                        style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    })]
                                })]
                            })]
                        })
                    })]
                })
            })
        }, g = function (e) {
            e && e instanceof Function && a.e(3).then(a.bind(null, 69)).then((function (t) {
                var a = t.getCLS, n = t.getFID, c = t.getFCP, s = t.getLCP, r = t.getTTFB;
                a(e), n(e), c(e), s(e), r(e)
            }))
        };
        r.a.render(Object(O.jsx)(c.a.StrictMode, {children: Object(O.jsx)(m, {})}), document.getElementById("root")), g()
    }
}, [[68, 1, 2]]]);
//# sourceMappingURL=main.be5e2ec9.chunk.js.map